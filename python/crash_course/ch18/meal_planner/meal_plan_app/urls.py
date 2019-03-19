#"""Defines URL patterns for meal_plan_app."""
from django.urls import path

from . import views  # import from same dir as current urls.py module

app_name = 'meal_plan_app'
urlpatterns = [
	# Home page.
	path('', views.index, name='index'),
]
