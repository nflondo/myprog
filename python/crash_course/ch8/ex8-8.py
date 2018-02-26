# 8-8
def make_album(artist_name, album_title, num_tracks=''):
    """Builds a dictionary describing a music album"""
    album_info = {'artist':artist_name, 'title':album_title}
    if num_tracks:
        album_info['tracks'] = num_tracks
    return album_info     

while True:
    artist = input("\nEnter album's artist: ")
    print("(enter 'q' at any time to quit)")
    if artist == 'q':
        break
    title = input("\nEnter album's title: ")
    if title == 'q':
        break
    album = make_album(artist, title)
    print(album)
   
    
