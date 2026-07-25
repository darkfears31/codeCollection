# Set the environment variables below (or hardcode them, but env vars are safer):
#  export SPOTIPY_CLIENT_ID="your_client_id"
#  export SPOTIPY_CLIENT_SECRET="your_client_secret"
#  export SPOTIPY_REDIRECT_URI="http://127.0.0.1:8888/callback"


import os
import spotipy
from spotipy.oauth2 import SpotifyOAuth

SCOPE = "user-read-currently-playing user-modify-playback-state user-read-playback-state"

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
if __name__ == "__main__":
    sp = get_client()
    result = sp.current_user_playing_track()
    if result is None or result.get("item") is None:
        print("No song is playing.")
        exit()
    is_playing = result.get("is_playing", False)
    if is_playing:
        print("Song is already playing.")
        exit()
    else:
        sp.start_playback()
