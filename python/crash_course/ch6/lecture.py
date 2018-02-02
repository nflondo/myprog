# Dictionaries
aliens = {'color':'green', 'points':5}
#print(aliens['color'])
#print(aliens['points'])
print(aliens)

aliens['x'] = 0
aliens['y'] = 25
print(aliens)

aliens['color'] = 'red'
print(aliens)

# Removing key-value pairs with del permanently
del aliens['points']
print(aliens)

