
class Song(object):
    
    def __init__(self, lyrics, title):
        self.lyrics = lyrics
        self.title = title
        
    def sing_me_a_song(self):
#        for line in self.lyrics:
#            print line
        print self.lyrics
        
    def __str__(self): 
        return self.title         
            
#happy_bday = Song(["Happy birthday to you", 
#                    "I don't want to get sued.",
#                    "So I'll stop right there"])
                    
#bulls_on_parade = Song(["They rally around the family",
#                        "With pockets full of shells"]) 
                        
# put lyrics in a var, then pass the var
#twinkle_lyrics = ['Twinkle twinle little star', 'how I wonder where you are']
twinkle_lyrics = ("Twinkle twinle little star, how I wonder where you are")
twinkle = Song(twinkle_lyrics, "Twinkle Song")                                           
                        
#happy_bday.sing_me_a_song()

#bulls_on_parade.sing_me_a_song()                        

twinkle.sing_me_a_song()

print '-' * 10
print "Will print object"
print twinkle
