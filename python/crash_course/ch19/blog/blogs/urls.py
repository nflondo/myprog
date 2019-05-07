"""Defines URL patterns for learning_logs."""

from django.urls import path

from . import views  # import from same dir as current urls.py module

app_name = 'blogs'
urlpatterns = [
	# Home page.
	path('', views.index, name='index'),
	
	# Show all posts.
	path('', views.posts, name='posts'),
]	
	
