local Enemies = {}

local image_path = "enemy.png"
local sprite_width = 156
local sprite_height = 145
local scale = 0.4
local hitbox_inset = 25 -- sprite pixels ignored on each side, so touching feels fair

local speed = 110 -- the player's speed is 200, so escaping is possible
local first_count = 1
local coins_per_enemy = 5
local max_enemies = 6

local spawn_distance = 400 -- new enemies appear at least this far from the player
local edge_margin = 20
local max_attempts = 50
local stop_distance = 1 -- stop moving when basically on top of the target
local separation_distance = 55 -- keeps enemies from merging into eachother

local bob_speed = 5
local bob_height = 4
local two_pi = math.pi * 2

local draw_width = sprite_width * scale
local draw_height = sprite_height * scale
local box_half_w = (sprite_width / 2 - hitbox_inset) * scale
local box_half_h = (sprite_height / 2 - hitbox_inset) * scale
local separation_sq = separation_distance * separation_distance
local spawn_sq = spawn_distance * spawn_distance

local function distSquared(x1, y1, x2, y2)
	local dx = x1 - x2
	local dy = y1 - y2
	return dx * dx + dy * dy
end

local function overlaps(ax, ay, aw, ah, bx, by, bw, bh)
	return ax < bx + bw and bx < ax + aw and ay < by + bh and by < ay + ah
end

-- x, y are the CENTER of the enemy
local function newEnemy(image, x, y)
	local self = {
		x = x,
		y = y,
		phase = love.math.random() * two_pi, -- so they don't bob in sync
	}

	function self:chase(dt, target_x, target_y)
		local dx = target_x - self.x
		local dy = target_y - self.y
		local dist = math.sqrt(dx * dx + dy * dy)
		if dist > stop_distance then
			self.x = self.x + (dx / dist) * speed * dt
			self.y = self.y + (dy / dist) * speed * dt
		end
	end

	function self:getBox()
		return self.x - box_half_w, self.y - box_half_h, box_half_w * 2, box_half_h * 2
	end

	function self:draw()
		local bob = math.sin(love.timer.getTime() * bob_speed + self.phase) * bob_height
		love.graphics.draw(image, self.x - draw_width / 2, self.y - draw_height / 2 + bob, 0, scale, scale)
	end

	return self
end

function Enemies.new(player)
	local image = love.graphics.newImage(image_path) -- loaded once, shared by all enemies
	local self = { list = {} }

	local function playerCenter()
		local hx, hy, hw, hh = player:getHitbox()
		return hx + hw / 2, hy + hh / 2
	end

	local function spawnOne()
		local win_w, win_h = love.graphics.getDimensions()
		local px, py = playerCenter()
		for _ = 1, max_attempts do
			local x = love.math.random(edge_margin, win_w - edge_margin)
			local y = love.math.random(edge_margin, win_h - edge_margin)
			if distSquared(x, y, px, py) >= spawn_sq then
				table.insert(self.list, newEnemy(image, x, y))
				return true
			end
		end
		return false
	end

	-- pushes overlapping enemies apart so they stay visibly separate
	local function separate()
		for i = 1, #self.list - 1 do
			local a = self.list[i]
			for j = i + 1, #self.list do
				local b = self.list[j]
				local dx = b.x - a.x
				local dy = b.y - a.y
				local dist_sq = dx * dx + dy * dy
				if dist_sq > 0 and dist_sq < separation_sq then
					local dist = math.sqrt(dist_sq)
					local push = (separation_distance - dist) / 2
					local nx = dx / dist
					local ny = dy / dist
					a.x = a.x - nx * push
					a.y = a.y - ny * push
					b.x = b.x + nx * push
					b.y = b.y + ny * push
				end
			end
		end
	end

	-- returns true when an enemy touches the player
	function self:update(dt, coins_collected)
		local wanted = math.min(first_count + math.floor(coins_collected / coins_per_enemy), max_enemies)
		while #self.list < wanted and spawnOne() do
		end

		local px, py = playerCenter()
		for _, enemy in ipairs(self.list) do
			enemy:chase(dt, px, py)
		end
		separate()

		local hx, hy, hw, hh = player:getHitbox()
		for _, enemy in ipairs(self.list) do
			local bx, by, bw, bh = enemy:getBox()
			if overlaps(hx, hy, hw, hh, bx, by, bw, bh) then
				return true
			end
		end
		return false
	end

	function self:draw()
		love.graphics.setColor(1, 1, 1, 1)
		for _, enemy in ipairs(self.list) do
			enemy:draw()
		end
	end

	return self
end

return Enemies
