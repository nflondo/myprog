

def scan(sentence=[]): 
    direction=['north', 'south', 'east', 'west']
    verb=['go', 'stop', 'kill', 'eat']
    # Empty list to store result
    result=[]
    # Takes input and separates it into words in a list
    words = sentence.split()
    # Converts each word in the list to lower case
    words = [element.lower() for element in words]
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

    
            
      
