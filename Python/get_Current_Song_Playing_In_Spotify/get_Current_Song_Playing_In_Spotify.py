# Set the environment variables below (or hardcode them, but env vars are safer):
#  export SPOTIPY_CLIENT_ID="your_client_id"
#  export SPOTIPY_CLIENT_SECRET="your_client_secret"
#  export SPOTIPY_REDIRECT_URI="http://127.0.0.1:8888/callback"

import os
import spotipy
from spotipy.oauth2 import SpotifyOAuth

SCOPE = "user-read-playback-state user-read-currently-playing"

# Authorize User, after first log in no more will be needed.
def get_client():
    return spotipy.Spotify(
        auth_manager = SpotifyOAuth(
            client_id=os.environ["SPOTIPY_CLIENT_ID"],
            client_secret=os.environ["SPOTIPY_CLIENT_SECRET"],
            redirect_uri=os.environ["SPOTIPY_REDIRECT_URI"],
            scope=SCOPE,
            cache_path=".spotify_cache"
        )
    )
# Returns said things of playing track
def get_now_playing(sp):
    result = sp.current_user_playing_track()
    if result is None or result.get("item") is None:
        return None
    track = result ["item"]
    artists = ", ".join(a["name"] for a in track["artists"])
    is_playing = result.get("is_playing", False)

    return {
        "track" : track["name"],
        "artists" :  artists,
        "album" : track["album"]["name"],
        "progress_ms" : result.get("progress_ms"),
        "duration_ms" : track["duration_ms"],
        "is_playing" : is_playing,
    }

if __name__ == "__main__":
    sp = get_client()
    now = get_now_playing(sp)
    if now is None:
        print("Nothing is playing RN.")
    else:
        status = "Playing" if now["is_playing"] else "Paused"
        print(f"{status}: {now['track']} - {now['artists']}")
        print(f"Album: {now['album']}")
        print(f"Progress: {now['progress_ms']/1000}s")
        print(f"Duration: {now['duration_ms']/1000}s")

