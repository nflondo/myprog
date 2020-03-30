import pytest

def test_true():
	assert True
	
def test_false():
	assert False

def test_key():
	first_list = ['a', 'b']
	second_list = ['b']
	assert first_list == second_list
