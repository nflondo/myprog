# Returns the IDs of the current top articles on Hacker News, and then examine
# each of the top articles.
import requests

from operator import itemgetter

# Make an API call and store the response.
url = 'https://hacker-news.firebaseio.com/v0/topstories.json'
r = requests.get(url)
print("Status code:", r.status_code)

# Process information about each submission.
submission_ids = r.json()
submission_dicts = []
for submission_id in submission_ids[:30]:
	# Make a separate API call for each submission.
	url = ('https://hacker-news.firebaseio.com/v0/item/' + str(submission_id) +
		'.json')
	submission_r = requests.get(url)
	print(submission_r.status_code)
	response_dict = submission_r.json()
	
#	try:
	submission_dict = {
		'title': response_dict['title'],
		'link': 'http://news.ycombinator.com/item?id=' + str(submission_id),
		'comments': response_dict.get('descendants', 0)
	}
#	except UnicodeEncodeError as e:
#			print("UnicodeEncodeError: ", e)

	submission_dicts.append(submission_dict)
	
submission_dicts = sorted(submission_dicts, key=itemgetter('comments'), 
					reverse=True)
					
for submission_dict in submission_dicts:
	try:
		print("\nTitle:", submission_dict['title'])
		print("Discussion link:", submission_dict['link'])
		print("Comments:", submission_dict['comments'])
	except UnicodeEncodeError as e:
		print("UnicodeEncodeError: ", e)
