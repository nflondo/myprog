# 8-7 album

def make_album(artist_name, album_title, num_tracks=''):
    """Builds a dictionary describing a music album"""
    album_info = {'artist':artist_name, 'title':album_title}
    if num_tracks:
        album_info['tracks'] = num_tracks
    return album_info
    
album = make_album('Marco A. Solis', 'Mas de mi alma')    
print(album)
album = make_album('Mana', 'Pedacito de Cielo')
print(album)
album = make_album('Magneto', 'Vuela, vuela', '8')
print(album)
