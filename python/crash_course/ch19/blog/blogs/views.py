from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.urls import reverse

from .models import BlogPost

# Create your views here.
def index(request):
	"""The home page for Blogs"""
	return render(request, 'blogs/index.html')

def posts(request):
	"""Show all posts."""
	# topics = Topic.objects.order_by('date_added')
	posts = BlogPost.objects.order_by('date_added')
	context = {'posts': posts}
	return render(request, 'blogs/posts.html', context)
