"""Defines URL patterns for learning_logs."""  

from django.urls import path  

from . import views  # import from same dir as current urls.py module  

app_name = 'pizzas' 

urlpatterns = [ 

    # Home page. 

    path('', views.index, name='index'), 

] 
