local newAnimation = require("animation")
local Player = {}

local hitbox_x = 8
local hitbox_y = 3
local hitbox_w = 42
local hitbox_h = 60
local frame_size = 66
local walk_time = 0.5
local scale = 2
local start_dir = "down"

function Player.new() -- center of window
	local animations = {
		left = newAnimation(love.graphics.newImage("walk_left.png"), frame_size, frame_size, walk_time),
		up = newAnimation(love.graphics.newImage("walk_up.png"), frame_size, frame_size, walk_time),
		down = newAnimation(love.graphics.newImage("walk_down.png"), frame_size, frame_size, walk_time),
		right = newAnimation(love.graphics.newImage("walk_right.png"), frame_size, frame_size, walk_time),
	}
	for _, animation in pairs(animations) do
		animation.spriteSheet:setFilter("nearest", "nearest")
	end

	local x, y = love.graphics.getDimensions()
	local self = {
		x = x / 2,
		y = y / 2,
		width = frame_size * scale,
		height = frame_size * scale,
		speed = 200,
		direction = start_dir,
		animations = animations,
	}
	function self:getHitbox()
		return self.x + hitbox_x * scale, self.y + hitbox_y * scale, hitbox_w * scale, hitbox_h * scale
	end
	function self:update(dt, rocks)
		local move_x = 0
		local move_y = 0
		if love.keyboard.isDown("w") then
			move_y = move_y - 1
		end
		if love.keyboard.isDown("s") then
			move_y = move_y + 1
		end
		if love.keyboard.isDown("a") then
			move_x = move_x - 1
		end
		if love.keyboard.isDown("d") then
			move_x = move_x + 1
		end
		-- not going into rocks checking
		for _, rock in ipairs(rocks) do
			local hx, hy, hw, hh = self:getHitbox()
			local push_x, push_y = rock:push(hx, hy, hw, hh)
			self.x = self.x + push_x
			self.y = self.y + push_y
		end
		if move_x ~= 0 or move_y ~= 0 then
			local dir = math.atan2(move_y, move_x)
			self.x = self.x + math.cos(dir) * self.speed * dt
			self.y = self.y + math.sin(dir) * self.speed * dt
			if move_x ~= 0 then
				self.direction = move_x < 0 and "left" or "right"
			else
				self.direction = move_y < 0 and "up" or "down"
			end

			local animation = self.animations[self.direction]
			animation.currentTime = animation.currentTime + dt
			if animation.currentTime >= animation.duration then
				animation.currentTime = 0
			end
		else
			for _, animation in pairs(self.animations) do
				animation.currentTime = 0
			end
		end

		-- Checking boundaries
		local dim_x, dim_y = love.graphics.getDimensions()
		if self.x + self.width >= dim_x then
			self.x = dim_x - self.width
		elseif self.x <= 0 then
			self.x = 0
		end
		if self.y + self.height >= dim_y then
			self.y = dim_y - self.height
		elseif self.y <= 0 then
			self.y = 0
		end
	end

	function self:draw()
		local animation = self.animations[self.direction]
		local spriteNum = math.floor(animation.currentTime / animation.duration * #animation.quads) + 1
		love.graphics.setColor(1, 1, 1, 1)
		love.graphics.draw(
			animation.spriteSheet,
			animation.quads[spriteNum],
			math.floor(self.x),
			math.floor(self.y),
			0,
			scale,
			scale
		)
	end
	return self
end

return Player
