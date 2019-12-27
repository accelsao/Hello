
import sys
import webbrowser

import spotipy
import spotipy.util as util
from spotipy.oauth2 import SpotifyClientCredentials
import argparse
import requests

def get_artist(name):
    results = sp.search(q='artist:' + name, type='artist')
    items = results['artists']['items']
    if len(items) > 0:
        return items[0]
    else:
        return None

def show_artist_albums(sp, artist):
    albums = []
    print(artist['id'])
    results = sp.artist_albums(artist['id'], album_type='album')
    print(results)
    albums.extend(results['items'])
    while results['next']:
        results = sp.next(results)
        albums.extend(results['items'])
    seen = set() # to avoid dups
    albums.sort(key=lambda album:album['name'].lower())
    for album in albums:
        name = album['name']
        if name not in seen:
            print((' ' + name))
            seen.add(name)

    print(seen)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--clientID', type=str, required=True)
    parser.add_argument('--clientSecret', type=str, required=True)
    parser.add_argument('--artist_name', type=str, required=True)
    args = parser.parse_args()

    auth = SpotifyClientCredentials(args.clientID, args.clientSecret)
    token = auth.get_access_token()
    sp = spotipy.Spotify(auth=token)


    artist = get_artist(args.artist_name)
    birdy_uri = 'spotify:artist:' + artist['id']
    print(birdy_uri)
    results = sp.artist_albums(birdy_uri, album_type='album')
    # print(results)
    # for i in results['items']:
    #     print(i)
    # for i in range(len(results['items'])):
    #     print(results['items'][i]['name'])

    # print(results['items'][0])
    # print('===================')
    url = results['items'][0]['external_urls']['spotify']
    chrome_path = 'C:\Program Files (x86)\Google\Chrome\Application\chrome.exe'

    webbrowser.register('chrome', None, webbrowser.BackgroundBrowser(chrome_path))
    webbrowser.get('chrome').open_new_tab(url)

# python main.py --clientID c8278b6b06b74d22b1d151c7f259a7f6 --clientSecret c6f50b69607f4ece8ae7d1cb8427df44 --artist_name toe
