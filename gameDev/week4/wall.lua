Wall = {}
Wall.__index = Wall

function Wall.new(x, y)
	local self = {}
	setmetatable(self, Wall)
	self.x = x
	self.y = y
	self.speed = 70
	self.width = 50
	self.height = 80
	self.color = { 0.6, 0.1, 0.9, 1.0 }
	return self
end

function Wall:draw()
	love.graphics.setColor(self.color)
	love.graphics.rectangle(self.x, self.y, self.width, self.height)
	love.graphics.setColor(1, 1, 1, 1)
end

return Wall
