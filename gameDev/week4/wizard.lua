Wizard = {}
Wizard.__index = Wizard

function Wizard.new(x, y)
	local self = {}
	setmetatable(self, Wizard)
	self.x = x
	self.y = y
	self.speed = 70
	self.width = 50
	self.height = 80
	self.color = { 0.5, 0.7, 0.3, 1.0 }
	return self
end

function Wizard:update(dt)
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

	local dir = math.atan2(move_y, move_x)
	if move_x ~= 0 or move_y ~= 0 then
		self.x = self.x + math.cos(dir) * self.speed * dt
		self.y = self.y + math.sin(dir) * self.speed * dt
	end
end

function Wizard:draw()
	love.graphics.setColor(self.color)
	love.graphics.rectangle(self.x, self.y, self.width, self.height)
	love.graphics.setColor(1, 1, 1, 1)
end

return Wizard
