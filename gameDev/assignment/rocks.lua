local Rock = {}

local min_count = 2
local max_count = 5
local min_radius = 20
local max_radius = 40
local rock_gap = 20 -- minimum free space between two rocks
local edge_margin = 20 -- minimum free space to the window edge
local player_safe_gap = 100 -- free space kept around the player's start
local max_attempts = 50 -- placement tries per rock, prevents endless loops

local fill_color = { 0.55, 0.55, 0.55 }
local outline_color = { 0.3, 0.3, 0.3 }
local outline_width = 3
local default_line_width = 1

local function distSquared(x1, y1, x2, y2)
	local dx = x1 - x2
	local dy = y1 - y2
	return dx * dx + dy * dy
end

function Rock.new(x, y, radius)
	local self = {
		x = x,
		y = y,
		radius = radius,
	}

	function self:draw()
		love.graphics.setColor(fill_color)
		love.graphics.circle("fill", self.x, self.y, self.radius)
		love.graphics.setColor(outline_color)
		love.graphics.setLineWidth(outline_width)
		love.graphics.circle("line", self.x, self.y, self.radius)
		love.graphics.setLineWidth(default_line_width)
		love.graphics.setColor(1, 1, 1, 1)
	end

	function self:push(rx, ry, rw, rh)
		local closest_x = math.max(rx, math.min(self.x, rx + rw))
		local closest_y = math.max(ry, math.min(self.y, ry + rh))

		local dx = closest_x - self.x
		local dy = closest_y - self.y
		local dist_sq = dx * dx + dy * dy

		if dist_sq >= self.radius * self.radius or dist_sq == 0 then
			return 0, 0
		end

		local dist = math.sqrt(dist_sq)
		local overlap = self.radius - dist
		return (dx / dist) * overlap, (dy / dist) * overlap
	end

	return self
end

local function isFree(x, y, radius, rocks, avoid_x, avoid_y)
	local safe = radius + player_safe_gap
	if distSquared(x, y, avoid_x, avoid_y) < safe * safe then
		return false
	end
	for _, other in ipairs(rocks) do
		local min_dist = radius + other.radius + rock_gap
		if distSquared(x, y, other.x, other.y) < min_dist * min_dist then
			return false
		end
	end
	return true
end

-- avoids to spawn onto player, with players coordinates given to it
function Rock.spawnMany(avoid_x, avoid_y)
	local dim_x, dim_y = love.graphics.getDimensions()
	local rocks = {}
	local count = love.math.random(min_count, max_count)

	for _ = 1, count do
		for _ = 1, max_attempts do
			local radius = love.math.random(min_radius, max_radius)
			local x = love.math.random(radius + edge_margin, dim_x - radius - edge_margin)
			local y = love.math.random(radius + edge_margin, dim_y - radius - edge_margin)
			if isFree(x, y, radius, rocks, avoid_x, avoid_y) then
				table.insert(rocks, Rock.new(x, y, radius))
				break
			end
		end
	end

	return rocks
end

return Rock
