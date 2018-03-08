# 9-7
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
            
class Admin(User):
    """child class from User."""
    
    def __init__(self, first_name, last_name, age, city, zip_code):
        super().__init__(first_name, last_name, age, city, zip_code)
        self.privileges = [
                'can add post', 
                'can delete post',
                'can delete user',
                ]
                
    def show_privileges(self):
        """show user privileges."""
        print("Admin privileges: ")
        for privilege in self.privileges:
            print(privilege)
            
my_admin = Admin('Dale', 'Bodily', '45', 'American Fork', '84655')
my_admin.show_privileges()
