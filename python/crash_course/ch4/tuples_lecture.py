# tuples are lists that cannot change (immutable)
dimensions = (200, 50)
print(dimensions[0])
print(dimensions[1])

# Writing over a Tuple
dimensions = (400, 100)
print(dimensions[0])
print(dimensions[1])

buffet = ('soup', 'meat', 'fruit', 'vegetables', 'drinks')
for item in buffet:
    print(item)
    
buffet = ('pasta', 'fish', 'fruit', 'vegetables', 'drinks') 
for item in buffet:
    print(item)
                                                                              
