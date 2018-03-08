""" Admin and Privileges module """
from user_mod import User
#import user_mod

class Privileges():
    """helper class."""
    def __init__(self):
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
            
class Admin(User):
#class Admin(User):
    """child class from User."""
    
    def __init__(self, first_name, last_name, age, city, zip_code):
        super().__init__(first_name, last_name, age, city, zip_code)
        self.privileges = Privileges()
