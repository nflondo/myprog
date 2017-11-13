from nose.tools import *
from ex48.lexicon import Lexicon
#import lexicon
#import ex48.lexicon.scan


def test_directions():
    lexicon = Lexicon()
    assert_equal(lexicon.scan("north"), [('direction', 'north')])
    result = lexicon.scan("north south east")
    assert_equal(result, [('direction', 'north'),
                            ('direction', 'south'),
                            ('direction', 'east')])

def test_verbs():
    lexicon = Lexicon()
    assert_equal(lexicon.scan("go"), [('verb', 'go')])
    result = lexicon.scan("go kill eat")
    assert_equal(result, [('verb', 'go'),
                        ('verb', 'kill'),
                        ('verb', 'eat')])                            
