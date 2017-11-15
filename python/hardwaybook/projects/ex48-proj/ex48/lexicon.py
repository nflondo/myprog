

def scan(sentence=[]): 
    direction=['north', 'south', 'east', 'west']
    verb=['go', 'stop', 'kill', 'eat']
    result=[]
    words = sentence.split()
    for item in words:
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
                 
    return result                

   
            
      
