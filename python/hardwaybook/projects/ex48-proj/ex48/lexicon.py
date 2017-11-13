

    
class Lexicon(object):
    
#    def __init__(self, sentence):
#        self.sentence = sentence


    def scan(self, sentence): 
        direction=['north', 'south', 'east', 'west']
        verb=['go', 'stop', 'kill', 'eat']
        result=[]
        for item in sentence:
            if item  in direction:
                direction_word=('direction',item)
#                print "Will print direction_word"
#                print direction_word
                result.append(direction_word)
            elif item in verb:
                verb_word=('verb',item)
                result.append(verb_word)
            else:
                error_word=('error',item)
                result.append(error_word)
                 
        print result                

    
#    stuff = raw_input('> ')
#    words = stuff.split()
#    scan(words)
            
      
