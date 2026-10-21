circle = {
	x = 300,
	y = 400,
	rad = 40,
	speed = 40,
	color = { r = 0.4, g = 0, b = 0.8 },
}
function love.load()
	timer = 1
end

function love.update(dt)
	local move_h = 0
	local move_v = 0

	if love.keyboard.isDown("w") then
		move_v = move_v - 1
	end
	if love.keyboard.isDown("s") then
		move_v = move_v + 1
	end
	if love.keyboard.isDown("a") then
		move_h = move_h - 1
	end
	if love.keyboard.isDown("d") then
		move_h = move_h + 1
	end

	local angle = math.atan2(move_v, move_h)
	if move_h ~= 0 or move_v ~= 0 then
		circle.x = circle.x + (circle.speed * math.cos(angle) * dt)
		circle.y = circle.y + (circle.speed * math.sin(angle) * dt)
	end
	timer = timer - dt
	if timer < 0 then
		circle.color.r = (circle.color.r + 0.01) % 1
		circle.color.g = (circle.color.g + 0.01) % 1
		circle.color.b = (circle.color.b + 0.01) % 1
	end
end

function love.draw()
	love.graphics.setColor(circle.color.r, circle.color.g, circle.color.b)
	love.graphics.circle("fill", circle.x, circle.y, circle.rad)
end

function love.keypressed(key)
	if key == "space" then
		circle.rad = circle.rad + 10
	end
end

function love.mousemoved(x, y)
	if x > 500 then
		circle.x = 150
	end
end
