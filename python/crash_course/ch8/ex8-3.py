# 8-3, 8-4 functions

def make_shirt(shirt_size='L', shirt_message='I love Python'):
    print("Shirt size is: " + shirt_size + " With message: " +
        shirt_message)

make_shirt()
make_shirt(shirt_size='M')
make_shirt(shirt_size='XL', shirt_message='You re never wrong to do' + 
    ' the rigth thing')

def describe_city(city_name, country='usa'):
    print(city_name + " is in " + country)
    
describe_city('Midvale')    
describe_city('Villahermosa', 'Mex')
describe_city(country='Spain', city_name='Barcelona') 

def city_country(city, country):
    print(city.title() + ", " + country.title())
    
city_country('Salt Lake City', 'USA')       
city_country('Buenos Aires', 'Argentina')       
