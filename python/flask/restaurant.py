#!/usr/bin/python
# 
from flask import Flask
from flask import render_template
import json

# This sets up a flask instance and calls it 'app'
app = Flask(__name__)

@app.route('/')
def main_page():
    return render_template('base.html', special="Hamburger")

if __name__=='__main__':
    app.run()
