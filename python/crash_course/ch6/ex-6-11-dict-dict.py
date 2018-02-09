# 6-11 Dictionary of Dictionaries

cities = {
    'villahermosa':{
            'country': 'mexico', 
            'population':'200,000', 
            'fact': 'very hot city',
            },
    'vernal':{
          'country': 'usa',
          'population': '30,000',
          'fact': 'dinosour quarry is there',
            },
    'provo':{
        'country': 'usa',
        'population': '250,000',
        'fact': 'college town',
        },
    }
            
for city, details in cities.items():
    print("\nCity: " + city)
    print("Country: " + details['country'])
    print("Population: " + details['population'])
    print("Interesting Fact: " + details['fact'])
