from nose.tools import *
from ex49 import Sentence

def test_directions():
    assert_equal(lexicon.scan("North"), [('direction', 'north')])
    result = lexicon.scan("north south east")
    assert_equal(result, [('direction', 'north'),
                            ('direction', 'south'),
                            ('direction', 'east')])v
