"""Defines URL patterns for learning_logs."""

from django.urls import path

from . import views  # import from same dir as current urls.py module

app_name = 'learning_logs'
urlpatterns = [
	# Home page.
	path('', views.index, name='index'),
	
	# Show all topics
	path('topics/', views.topics, name='topics'),
	
	# Details page for a single topic
	path('topics/<int:topic_id>', views.topic, name='topic'),
	
	# Page for adding a new topic
	path('new_topic/', views.new_topic, name='new_topic'),
]
