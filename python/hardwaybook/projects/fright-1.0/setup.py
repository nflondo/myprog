# File used to install project

try:
    from setuptools import setup
    
except ImportError:
    from distutils.core import setup
    
config = {
    'description': 'Frightmares',
    'author': 'Nefi Munoz',
    'url' : 'https://github.com/nflondo/myprog/tree/master/python',
    'download_url': 'https://github.com/nflondo/myprog/tree/master/python',
    'author_email': 'nefi.munoz@gmail.com',
    'version' : '0.1',
    'install_requires': ['nose'],
    'packages': ['frightmares'],
    'scripts': [],
    'name' : 'frightmares'
}

setup(**config)
