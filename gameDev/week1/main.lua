function love.load()
	x1, y1, rad = 200, 300, 15
	x2, y2 = 400, 150
	width = love.graphics.getWidth()
	height = love.graphics.getHeight()
	directionX1, directionX2 = 1, 1
	directionY1, directionY2 = 1, 1
	color1 = { math.random(), math.random(), math.random() }
	color2 = { math.random(), math.random(), math.random() }
end

function love.update(dt)
	x1 = x1 + 150 * directionX1 * dt
	y1 = y1 + 150 * directionY1 * dt
	x2 = x2 + 150 * directionX2 * dt
	y2 = y2 + 150 * directionY2 * dt

	if x1 >= width - rad then
		directionX1 = -1
		randomColor(color1)
	elseif x1 <= rad then
		directionX1 = 1
		randomColor(color1)
	end

	if y1 >= height - rad then
		directionY1 = -1
		randomColor(color1)
	elseif y1 <= rad then
		directionY1 = 1
		randomColor(color1)
	end

	if x2 >= width - rad then
		directionX2 = -1
		randomColor(color2)
	elseif x2 <= rad then
		directionX2 = 1
		randomColor(color2)
	end

	if y2 >= height - rad then
		directionY2 = -1
		randomColor(color2)
	elseif y2 <= rad then
		directionY2 = 1
		randomColor(color2)
	end
end

function love.draw()
	love.graphics.setColor(color1)
	love.graphics.circle("fill", x1, y1, rad)
	love.graphics.setColor(color2)
	love.graphics.circle("fill", x2, y2, rad)
end

-- let's use tables.
function randomColor(color)
	color[1] = math.random()
	color[2] = math.random()
	color[3] = math.random()
end
