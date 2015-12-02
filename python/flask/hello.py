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

if __name__=='__main__':
    app.run()
