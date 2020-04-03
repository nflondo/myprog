# Running particular tests
import pytest

@pytest.mark.dicttest # "dicttest" is the keyword used to mark it/tag it
def test_something():
    a = ['a', 'b']
    assert a == a
    
def test_something_else():
    assert False
