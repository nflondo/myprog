""" Represents a user. """

class User():
    
    def __init__(self, first_name, last_name, age, city, zip_code):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
        self.city = city
        self.zip_code = zip_code
        
    def describe_user(self):
        print("Name: "+ self.first_name.title() + " " + 
            self.last_name.title())
        print("Age: " + self.age )
        print("City: " + self.city + "\tZip Code: " + self.zip_code)
        
    def greet_user(self):
        print("\nWelcome " + self.first_name.title() + " " + 
            self.last_name.title())
