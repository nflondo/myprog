#!/usr/bin/python3
# Class to create a chart object

class Chart(object):
    def __init__(self, name, vendor, date_updated):
        self.name = name
        self.vendor = vendor
        self.date_updated = date_updated

    def print_chart(self):
        print(self.name + " " + self.vendor + " " + self.date_updated)

    def __str__(self):
        return f'Chart(name={self.name}, vendor={self.vendor}, date_updated={self.date_updated})'
        