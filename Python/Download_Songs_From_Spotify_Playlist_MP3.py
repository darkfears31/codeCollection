# Set the environment variables below (or hardcode them, but env vars are safer):
#  export SPOTIPY_CLIENT_ID="your_client_id"
#  export SPOTIPY_CLIENT_SECRET="your_client_secret"
#  export SPOTIPY_REDIRECT_URI="http://127.0.0.1:8888/callback"

import os
import yt_dlp
import spotipy
from spotipy.oauth2 import SpotifyOAuth

SCOPE = "user-read-playback-state user-read-currently-playing playlist-read-private playlist-read-collaborative"

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
def find_playlist(sp, name):
    playlists = []
    results = sp.current_user_playlists(limit=50)
    playlists.extend(results["items"])

    while results["next"]:
        results = sp.next(results)
        playlists.extend(results["items"])
    matches = [p for p in playlists if p["name"].lower() == name.lower()]
    if not matches:
        print(f"No playlist found named: '{name}'")
        return None 
    else:
        return matches[0]["id"]

def get_playlist_tracks(sp, playlist_id):
    tracks = []
    results = sp.playlist_items(playlist_id, additional_types=["track"])
    items = results["items"]
    while results["next"]:
        results = sp.next(results)
        items.extend(results["items"])
    for entry in items:
        track = entry.get("item")
        if track is None:
            continue
        artists = ", ".join(a["name"] for a in track["artists"])
        tracks.append({
            "name" : track["name"],
            "artists" : artists,
        })
    return tracks

if __name__ == "__main__":
    sp = get_client()
    playlist_name = input("Enter playlist name: ").strip()
    playlist_id = find_playlist(sp, playlist_name)
    if playlist_id is None:
        exit()
    print(f"===== Songs In '{playlist_name}' =====")
    download_dir = f"{playlist_name}"
    os.makedirs(download_dir, exist_ok=True)
    for t in get_playlist_tracks(sp, playlist_id):
        print(f"{t['name']} {t['artists']}")
        song = f"{t['name']} {t['artists']}"
        options = {
            "format": "bestaudio/best",
            "outtmpl": os.path.join(download_dir, "%(title)s.%(ext)s"),
            "default_search": "ytsearch1",
            "postprocessors": [
                {
                    "key": "FFmpegExtractAudio",
                    "preferredcodec": "mp3",
                    "preferredquality": "192",
                }
            ],
        }

        with yt_dlp.YoutubeDL(options) as ydl:
            ydl.download([song])

