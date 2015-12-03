#!/usr/bin/python
# Run hello world on http://127.0.0.1:5000/
from flask import Flask

# This sets up a flask instance and calls it 'app'
app = Flask(__name__)

# @ is a decorator (advanced topic) Where the app is going to be served (at /)
# Follow by function, together they create a "view"
@app.route('/')
def hello_world():
    return 'Hello Beautiful World !'

@app.route('/test/')
def test_page():
    return "This is a test page !!"

@app.route('/longer/path/to/page')
def deep_page():
    return "Another page in longer path !!"
# The variable <name> is replaced with whatever the user types in path
@app.route('/<name>/')
def name_page(name):
    return "Hello, {name}".format(name=name)

if __name__=='__main__':
    app.run()
