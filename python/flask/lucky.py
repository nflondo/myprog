#!/usr/bin/python
# 
from flask import Flask
from flask import render_template
from random import randint

# This sets up a flask instance and calls it 'app'
app = Flask(__name__)

@app.route('/')
def lucky():
    lucky_num = randint(1,10)
    return render_template('lucky.html', lucky_num=lucky_num)

if __name__=='__main__':
    app.run()
