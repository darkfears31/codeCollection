import discord
import subprocess

SCRIPT1_CMD = ["python3", "/home/kaikaci/Desktop/python/get_Info.py"]
CHANNEL_ID = #channel ID

intents = discord.Intents.default()
intents.message_content = True

client = discord.Client(intents=intents)

async def run_and_send(channel, cmd):
    result = subprocess.run(cmd, capture_output=True, text=True)
    output = result.stdout + result.stderr
    await channel.send(f'```\n{output[:1900] or "(no output)"}```')

@client.event
async def on_ready():
    channel = client.get_channel(CHANNEL_ID)
    await run_and_send(channel, SCRIPT1_CMD)
    await channel.send(file=discord.File("/home/kaikaci/Desktop/python/selfie.jpg"))
    subprocess.run(["rm", "/home/kaikaci/Desktop/python/selfie.jpg"])
    await client.close()

client.run(#bot_token)
