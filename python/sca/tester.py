#!/usr/bin/env python3
# Author: Nefi Munoz (nmunoz@xmission.com)
#  write code that parse the nginx access.log (under /home/logs/access.log) and print statistics
# - The statistics we want to see are:
#   1. The number of calls
#   2. The number of uniqe calls by method+path
#   Example output should look like:

#         Total of 6 calls
#         Unique calls:
#         GET / : 1
#         GET /something : 1
#         POST /something : 2
#         DELETE /something : 1
#         DELETE /HTTP/1.1 : 1
# 172.17.0.1 - - [08/Nov/2021:14:55:39 +0000] "GET / HTTP/1.1" 200 615 "-" "curl/
# 
#
import re
# Path to log file to parse
#access_file = '/home/logs/access.log'
access_file = '/root/myprog/python/sca/access.log'
#
#=============================================================================#
# Function opens log file and reads it line by line; each line is searched
# for pattern given if found increate count.  Return the final count
def search_calls(pattern):
    line_num = 0
    found = 0
#    patterns = ['GET', 'POST', 'DELETE']
    #substr = "".lower()
    with open(access_file, 'r') as f_obj:
        for line in f_obj:
            line_num += 1
#            for pattern in patterns:
            if re.search(pattern, line):
#                print("Found a match!")
                found +=1
#            else:
#                print("no match")

#    print("Found: %d" % found)
    return found

# Get specified patterns
# Search for any of GET, POST, or DELETE
pattern = "GET|POST|DELETE"
print("Total of %d calls" % (search_calls(pattern)))

print("Unique calls:")

# Search for GET followed by space followed by / followed by space
pattern = "GET / "
print("%s : %d" % (pattern, (search_calls(pattern))))

# Search for GET followed by space followed by / followed by any non-white space char
pattern = "GET /\S"
print("GET /something : %d" % (search_calls(pattern)))

# Search for POST followed by space followed by / followed by any non-white space char
pattern = "POST /\S"
print("POST /something : %d" % (search_calls(pattern)))

# Search for DELETE followed by space followed by / followed by any non-white space char
pattern = "DELETE /\S"
print("DELETE /something : %d" % (search_calls(pattern)))

pattern = "DELETE /HTTP/1.1"
print("DELETE /HTTP/1.1 : %d" % (search_calls(pattern)))
