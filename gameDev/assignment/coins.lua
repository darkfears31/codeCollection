local Coins = {}

local start_count = 5
local radius_x = 10 -- oval: narrower than tall
local radius_y = 14
local edge_margin = 20 -- free space to the window edge
local rock_gap = 10 -- free space between a coin and a rock
local coin_gap = 40 -- minimum distance between two coins
local player_gap = 150 -- new coins never appear this close to the player
local max_attempts = 50 -- placement tries per coin, prevents endless loops

local spin_speed = 4
local min_spin_scale = 0.15 -- keeps the coin from vanishing when edge-on
local two_pi = math.pi * 2

local fill_color = { 1, 0.85, 0.1 }
local outline_color = { 0.7, 0.5, 0 }
local outline_width = 2
local default_line_width = 1

local function distSquared(x1, y1, x2, y2)
	local dx = x1 - x2
	local dy = y1 - y2
	return dx * dx + dy * dy
end

local function overlaps(ax, ay, aw, ah, bx, by, bw, bh)
	return ax < bx + bw and bx < ax + aw and ay < by + bh and by < ay + ah
end

local function newCoin(x, y)
	local self = {
		x = x,
		y = y,
		phase = love.math.random() * two_pi, -- so coins don't spin in sync
	}

	function self:getBox()
		return self.x - radius_x, self.y - radius_y, radius_x * 2, radius_y * 2
	end

	function self:draw()
		local spin = math.abs(math.cos(love.timer.getTime() * spin_speed + self.phase))
		local width = math.max(min_spin_scale, spin) * radius_x

		love.graphics.setColor(fill_color)
		love.graphics.ellipse("fill", self.x, self.y, width, radius_y)
		love.graphics.setColor(outline_color)
		love.graphics.setLineWidth(outline_width)
		love.graphics.ellipse("line", self.x, self.y, width, radius_y)
		love.graphics.setLineWidth(default_line_width)
		love.graphics.setColor(1, 1, 1, 1)
	end

	return self
end

function Coins.new(rocks, player)
	local self = {
		list = {},
		collected = 0, -- internal counter, used to spwan more enemies
		pending = start_count, -- coins still waiting to be spawned
	}

	local function playerCenter()
		return player.x + player.width / 2, player.y + player.height / 2
	end

	local function isFree(x, y)
		local px, py = playerCenter()
		if distSquared(x, y, px, py) < player_gap * player_gap then
			return false
		end
		for _, rock in ipairs(rocks) do
			local min_dist = rock.radius + radius_y + rock_gap
			if distSquared(x, y, rock.x, rock.y) < min_dist * min_dist then
				return false
			end
		end
		for _, coin in ipairs(self.list) do
			if distSquared(x, y, coin.x, coin.y) < coin_gap * coin_gap then
				return false
			end
		end
		return true
	end

	local function spawnOne()
		local win_w, win_h = love.graphics.getDimensions()
		for _ = 1, max_attempts do
			local x = love.math.random(radius_x + edge_margin, win_w - radius_x - edge_margin)
			local y = love.math.random(radius_y + edge_margin, win_h - radius_y - edge_margin)
			if isFree(x, y) then
				table.insert(self.list, newCoin(x, y))
				return true
			end
		end
		return false
	end

	-- spawns everything that is waiting; stops for this frame if no free spot is found
	local function refill()
		while self.pending > 0 and spawnOne() do
			self.pending = self.pending - 1
		end
	end

	function self:update()
		local hx, hy, hw, hh = player:getHitbox()
		for i = #self.list, 1, -1 do
			local bx, by, bw, bh = self.list[i]:getBox()
			if overlaps(hx, hy, hw, hh, bx, by, bw, bh) then
				table.remove(self.list, i)
				self.collected = self.collected + 1
				self.pending = self.pending + 1
			end
		end
		refill()
	end

	function self:draw()
		for _, coin in ipairs(self.list) do
			coin:draw()
		end
	end

	refill() -- add coins
	return self
end

return Coins
