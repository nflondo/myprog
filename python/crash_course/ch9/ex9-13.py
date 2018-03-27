from collections import OrderedDict

my_glossary = OrderedDict()

my_glossary['dictionary']='A collection of key-value pairs'
my_glossary['list']='A collection of items in a particular order'
my_glossary['tuple']='An immutable list'
my_glossary['key']='Index in a dictionary'
my_glossary['value']='The value of the key'

 
for key, value in my_glossary.items():
    print("\n" + key.title() + ": " + value)
    
    
