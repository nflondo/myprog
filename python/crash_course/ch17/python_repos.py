#python_repos.py
# Make an API call and store the response.
import requests
import pygal
from pygal.style import LightColorizedStyle as LCS, LightenStyle as LS
# Based on Schema from Github REST API V3 Documentation at 
# https://developer.github.com/v3/ All API access is over HTTPS, user-agent
# is required.  This is the API call.
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

names, stars = [], []
for repo_dict in repo_dicts:
	names.append(repo_dict['name'])
	stars.append(repo_dict['stargazers_count'])
	
# Make Visualization
my_style = LS('#333366', base_style=LCS)
chart = pygal.Bar(style=my_style, x_label_rotation=45, show_legend=False)
chart.title = 'Most-Starred Python Projects on GitHub'
chart.x_labels = names

# Not labeling this data series
chart.add('', stars)
chart.render_to_file('python_repos.svg')
#print("Repositories returned:", len(repo_dicts))

# Examine the first repository
#repo_dict = repo_dicts[0]

# Examine all repos
#for repo_dict in repo_dicts:
#	try:
#		print("-" * 45)
#		print("Name:", repo_dict['name'])
#		print("Owner:", repo_dict['owner']['login'])
#		print("Stars:", repo_dict['stargazers_count'])
#		print("Repository:", repo_dict['html_url'])
#		print('Description:', repo_dict['description'])
#	except UnicodeEncodeError:
#		print("***Unicode error for Repo: ", repo_dict['name'])
