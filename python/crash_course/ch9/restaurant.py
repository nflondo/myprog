"""This represents a restaurant"""

class Restaurant():
    
    def __init__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type
        self.number_served = 0
        
    def describe_restaurant(self):
        print("Restaurant Name: " + self.restaurant_name)
        print("Cuisine Type: " + self.cuisine_type)
        
    def open_restaurant(self):
        print("\n Restaurant " + self.restaurant_name + " is opened !!")
        
    def set_number_served(self, num_customers):
        self.number_served = num_customers
    
    def increment_number_served(self, number):
        self.number_served += number
        
