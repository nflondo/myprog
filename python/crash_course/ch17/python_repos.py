#python_repos.py
# Make an API call and store the response.
import requests
# Based on Schema from Github REST API V3 Documentation at 
# https://developer.github.com/v3/ All API access is over HTTPS, user-agent
# is required
url = 'https://api.github.com/search/repositories?q=language:python&sort=stars'
headers = {'user-agent':'Mozilla/5.0 (X11; Linux x86_64; rv:60.0) Gecko/20100101 Firefox/60.0 nflondo'}
# Found example online of how to pass auth in requests.get
r = requests.get(url, headers=headers, auth=('nflondo', 'wllalMD2'))
# status code=200 is success
print("Status code:", r.status_code)
# Store API response in a variable
response_dict = r.json()
print("Total repositories:", response_dict['total_count'])

# Explore information about the repositories.
repo_dicts = response_dict['items']
print("Repositories returned:", len(repo_dicts))

# Examine the first repository
repo_dict = repo_dicts[0]
print("\nKeys:", len(repo_dict))
#for key in sorted(repo_dict.keys()):
print("Repo Name:", repo_dict['name'])

for key in repo_dict.keys():	
	print(key)

# Process results.
#print(response_dict.keys())
