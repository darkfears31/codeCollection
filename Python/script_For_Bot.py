import discord
import subprocess

intents = discord.Intents.default()
intents.message_content = True

client = discord.Client(intents=intents)

@client.event
async def on_ready():
    print(f'We have logged in as {client.user}')

@client.event
async def on_message(message):
    if message.author == client.user:
        return
    #running commands
    if message.content.startswith('$run'):
        cmd = message.content[len('$run'):]
        result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
        output = result.stdout + result.stderr
        await message.channel.send(f'```\n{output[:1900] or "(no output)"}```')
    # sending photo
    if message.content.startswith('$photo '):
        path = message.content[len('$photo '):]
        await message.channel.send(file=discord.File(path))

client.run('bot_token')
