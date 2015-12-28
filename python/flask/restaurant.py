#!/usr/bin/python
# 
from flask import Flask
from flask import render_template
import json
from datetime import datetime



# This sets up a flask instance and calls it 'app'
app = Flask(__name__)

def get_specials(filename):
    f = open(filename)
    specials = json.load(f)
    f.close()
    return specials

def get_special():
    specials = get_specials('specials.json')
    today = datetime.now()
    DAYS_OF_WEEK = ('monday', 'tuesday', 'wednesday', 'thursday', 'friday', 'saturday', 'sunday')
    weekday = DAYS_OF_WEEK[today.weekday()]
    return specials[weekday]
   
@app.route('/')
def main_page():
    return render_template('base.html', special= get_special())
    
@app.route('/bios/')
def bios_page():
    f = open('bio.json')
    bios = json.load(f)
    f.close
    return render_template('bios_page.html', bios=bios['bios'])

if __name__=='__main__':
    app.run()
