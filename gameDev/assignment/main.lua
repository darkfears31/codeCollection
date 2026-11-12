local Player = require("player")
local Enemies = require("enemy")
local Rocks = require("rocks")
local Coins = require("coins")

function love.load()
	love.graphics.setBackgroundColor(0, 1, 0) -- bg colour
	love.window.setMode(1200, 900) -- set window size.
	player = Player.new()
	rocks = Rocks.spawnMany(player.x, player.y)
	coins = Coins.new(rocks, player)
	enemies = Enemies.new(player)
end

function love.update(dt)
	player:update(dt, rocks)
	coins:update()
	if enemies:update(dt, coins.collected) then
		love.event.quit()
	end
end

function love.draw()
	for _, rock in ipairs(rocks) do
		rock:draw()
	end
	coins:draw()
	player:draw()
	enemies:draw()
end
