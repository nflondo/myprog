"""Defines URL patterns for learning_logs."""

from django.urls import path

from . import views  # import from same dir as current urls.py module

app_name = 'learning_logs'
urlpatterns = [
	# Home page.
	path('', views.index, name='index'),
]
