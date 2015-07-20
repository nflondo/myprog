#!/usr/bin/python
# demo function passing parameters by name

def print_total(customer_name, items):
    print "Total for {0}:".format(customer_name)
    total = 0
    for item in items:
        total = total + item
    print "${0}".format(total)


print_total(items=[5.0, 5.5, 5.0], customer_name="Alfred")
