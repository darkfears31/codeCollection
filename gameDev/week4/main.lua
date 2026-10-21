require("wizard")
require("wall")

function love.load()
	wizard = Wizard.new(300, 400)
	wall = Wall.new(600, 700)
end

function love.update(dt)
	wizard:update(dt)
end

function love.draw()
	wizard.draw()
	wall.draw()
end
