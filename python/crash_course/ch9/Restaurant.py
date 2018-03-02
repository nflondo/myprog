# 9-1

class Restaurant():
    
    def __init__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type
        
    def describe_restaurant(self):
        print("Restaurant Name: " + self.restaurant_name)
        print("Cuisine Type: " + self.cuisine_type)
        
    def open_restaurant(self):
        print("\n Restaurant " + self.restaurant_name + " is opened !!")
        
my_restaurant = Restaurant('Bajio', 'Mexican')
print(my_restaurant.restaurant_name)
print(my_restaurant.cuisine_type)

my_restaurant.describe_restaurant()
my_restaurant.open_restaurant()

restaurant2 = Restaurant('Olive Garden', 'Italian')
restaurant3 = Restaurant('Village Inn', 'American')

restaurant2.describe_restaurant()
restaurant3.describe_restaurant()
