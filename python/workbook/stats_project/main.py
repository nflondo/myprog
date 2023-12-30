#!/usr/bin/python3
# This program will get applications updated in the last year and write them in 
# a report.  The report will contain columns such as app name, date updated, vendor
import json
from classes.chart import Chart

def main():
    #/home/nmunoz/github-repos/partner-charts/index.yaml
    # Read target_file line by line and if the line contains 'release-name' then
    # add the name of the chart a class object and add it to a list.  The list will
    # contain all the chart objects.  The chart object will have the following
    # attributes: name, vendor, date_updated.  The date_updated will be the date
    # the chart was updated in the index.yaml file.  The name will be the name of
    # the chart.  The vendor will be the vendor of the chart.  The vendor will be

    target_file="/home/nmunoz/github-repos/partner-charts/index.yaml"
    chart_dict={}    
    with open( target_file, 'r') as file_object:
        for line in file_object: # read file line by line
            # chart_name contains name after ':' in line and without spaces            
            if 'release-name:' in line:
                chart_name = line.split(':')[1].strip()
                chart = Chart(chart_name, 'vendor', 'date_updated')
                # only add chart_name to chart_dict if it is not already in chart_dict
                if chart.name not in chart_dict:                   
                    #chart_name.print_chart()
                    chart_dict[chart.name] = chart_name                              
            # Add the date_updated to the chart object
            if 'created:' in line:
                chart_updated = line.split(':')[1].strip()
                chart_dict[chart.name] = chart.date_updated = chart_updated
            
            # Add the vendor to the chart object            
            if 'email:' in line:    
                chart_vendor = line.split(':')[1].strip()                
                chart_dict[chart.name] = chart.vendor = chart_vendor 
                chart.print_chart()
    #dump dictionary to a json file
    # with open('chart_dict.json', 'w') as f:
    #     json.dump(chart_dict, f, indent=4) 

# only call the main function when this file has not been imported
if __name__== "__main__": 
    main()