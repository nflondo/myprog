#python_repos.py
# Make an API call and store the response.
import requests
url = 'http://api.github.com/search/repositories?q=language:python&sort=stars'
r = requests.get(url)
# status code=200 is success
print("Status code:", r.status_code)
# Store API response in a variable
response_dict = r.json()

# Process results.
print(response_dict.keys())
