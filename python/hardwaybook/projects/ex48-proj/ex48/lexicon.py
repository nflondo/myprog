# This is a scanner that takes a string of raw input and returns a sentence
# that is composed of a list of tuples with the (TOKEN, WORD) pairings.
# If a word isn't part of the lexicon, then it returns the WORD with 
# TOKEN set to error.

def scan(sentence=[]): 
    direction=['north', 'south', 'east', 'west']
    verb=['go', 'stop', 'kill', 'eat']
    stop=['the', 'in', 'of', 'from', 'at', 'it']
    noun=['door', 'bear', 'princess', 'cabinet']
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
        elif item in stop:
            stop_word=('stop', item)
            result.append(stop_word)
        elif item in noun:
            noun_word=('noun', item)
            result.append(noun_word)                   
        else:
            error_word=('error',item)
            result.append(error_word)
                 
    return result                

    
            
      
