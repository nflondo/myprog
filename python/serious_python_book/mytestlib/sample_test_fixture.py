# simple fixture
# the db fixture is automatically used by any test that has a database in its
# argument list.  The test_insert will receive the result of database and use
# that result as it wants.
# In this way, we don't need to repeat the database initialization code several times.
import pytest

@pytest.fixture
def database():
    return # <some db connection>
    
def test_insert(database):
    database.insert(123)
    
