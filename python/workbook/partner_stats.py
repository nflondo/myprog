#!/usr/bin/python3
# This program reads file and gets chart names, created dates, and email addresses
# from the file.  It then creates a dictionary for each chart name and adds the 
# created date and email address to the dictionary.  Next, it adds the dictionary
# to a list.  Finally, it prints the list and dumps the list to a file.
# Author: Nefi Munoz <nefi.munoz at gmail.com>

import re

def dump_to_csv(list):
    '''Dumps the list to a csv file'''
    output_file = 'charts_stats.csv'
    with open(output_file, 'w') as f:
        for chart in list:
            f.write(chart['name'] + ',' + chart['created'] + ',' + chart['vendor'] + '\n')

def print_list(list):
    '''Prints the list'''
    for item in list:
        print(item)

def main():
    target_file='/home/nmunoz/github-repos/partner-charts/index.yaml'
    all_charts = []
    # This list contains the name of the charts already added to all_charts list
    added_names = []
    name_found = False
    created_found = False
    vendor_found = False
    # Open the file for reading    
    with open(target_file, 'r') as file_object:
        for line in file_object: # read file line by line
            # Get char name from line with 'release-name:'
            if 'release-name:' in line:
                chart_name = line.split(':')[1].strip()
                name_found = True
            # Get created date from line with 'created:' and drop quotes
            if 'created:' in line:
                match = re.search(r'\d{4}-\d{2}-\d{2}', line)
                if match:
                    chart_created = match.group() # returns the matched substring
                    created_found = True
            # Get vendor name from the line with 'email:'
            if 'email:' in line:
                chart_vendor = line.split(':')[1].strip()
                vendor_found = True
            # Create a dictionary for each chart name and add the created date and
            # vendor to the dictionary
            if name_found and created_found and vendor_found:
                # Reset the flags
                name_found = False
                created_found = False
                vendor_found = False
                # Create a dictionary for the chart
                chart_dict = {'name': chart_name, 
                            'created': chart_created, 
                            'vendor': chart_vendor,
                            }
                # Add only the first dictionary found to the list
                if chart_dict['name'] not in added_names:
                    all_charts.append(chart_dict)
                    added_names.append(chart_dict['name'])

    # Print the list of dictionaries
    print_list(all_charts)

    # Dump the list of values in dictionaries to a comma separated file
    dump_to_csv(all_charts)

if __name__ == "__main__":
    main()