
class ParserError(Exception):
    pass
    
class Sentence(object):

    def __init__(self, subject, verb, object):
        # remember we take ('noun', 'princess') tuples and convert them
        self.subject = subject[1]
        self.verb = verb[1]
        self.object = object[1]
            

def peek(word_list):
    if word_list:
        word = word_list[0]
        return word[0]
    else:
        return None
        
def match(word_list, expecting):
    if word_list:
        word = word_list.pop(0)
        
        if word[0] == expecting:
            return word
        else:
            return None
            
    else:
        return None
        
def skip(word_list, word_type):
    while peek(word_list) == word_type:
        match(word_list, word_type)  
        
def parse_verb(word_list):
    skip(word_list, 'stop')
    
    if peek(word_list) == 'verb':
        return match(word_list, 'verb')
    else:
        raise ParserError("Expected a verb next.")
        
def parse_object                                                                    
