#!/usr/bin/python
# 
from flask import Flask
from flask import render_template

# This sets up a flask instance and calls it 'app'
app = Flask(__name__)

@app.route('/')
def lucky():
    return render_template('lucky.html')

if __name__=='__main__':
    app.run()
