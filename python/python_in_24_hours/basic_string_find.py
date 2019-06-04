#!/usr/bin/python
# if string contains emergency, then ask if email is urgent
# If string contains joke, then ask if email is non-urgent

#email_1="This is an urgent message"

email_1="This is a good joke"

if email_1.find('urgent') != -1:
    print "Do you want to send as urgent message?"
elif email_1.find('joke') != -1:
    print "Do you want to send as non-urgent message?"
    

