# 9-6

class Restaurant():
    
    def __init__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type
        
    def describe_restaurant(self):
        print("Restaurant Name: " + self.restaurant_name)
        print("Cuisine Type: " + self.cuisine_type)
        
    def open_restaurant(self):
        print("\n Restaurant " + self.restaurant_name + " is opened !!")
        
class IceCreamStand(Restaurant):
    """Child class from Restaurant."""
    def __init__(self,restaurant_name, cuisine_type):
        """initialize parent class attributes"""
        super().__init__(restaurant_name, cuisine_type)
        self.flavors = ['vanilla', 'chocolate', 'strawberry']
        
    def display_flavors(self):
        for flavor in self.flavors:
            print(flavor)
            
my_cream = IceCreamStand('Dairy Queen', 'American')
my_cream.display_flavors()
