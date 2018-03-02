# car class
class Car():
    """A simple attempt to represent a car"""
    
    def __init__(self, make, model, year):
        """Initialize attributes to describe a car."""
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0  # value is set here, so no need to
                                    # pass it as argument (default val)
        
    def get_descriptive_name(self):
        """Return a neatly formatted descriptive name."""
        long_name = str(self.year) + ' ' + self.make + ' ' + self.model
        return long_name.title()
        
    def read_odometer(self):
        """Print a statement showing the car's mileage."""              
        print("This car has " + str(self.odometer_reading) + 
            " miles on it.")
            
    def update_odometer(self, mileage):
        """
        Set the odometer reading to the given value.
        Reject the change if it attempts to roll the odometer back.
        """
        if mileage >= self.odometer_reading:
            self.odometer_reading = mileage
        else:
            print("You can't roll back an odometer!")
            
    # Incrementing/modifying an attribute value
    def increment_odometer(self, miles):
        """Add the given amount to the odometer reading."""
        self.odometer_reading += miles
            
my_new_car = Car('audi', 'a4', 2016)
print(my_new_car.get_descriptive_name())        
my_new_car.read_odometer()

# modify directly
my_new_car.odometer_reading = 23
my_new_car.read_odometer()

# modify through a method
my_new_car.update_odometer(60)
my_new_car.read_odometer()

# Add logic to check for roll back odometer
my_new_car.update_odometer(30)
my_new_car.read_odometer()

# Incrementing/modifying an attribute value
my_new_car.increment_odometer(100)
my_new_car.read_odometer()
