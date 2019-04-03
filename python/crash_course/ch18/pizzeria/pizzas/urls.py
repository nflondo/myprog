"""Defines URL patterns for learning_logs."""  

from django.urls import path  

from . import views  # import from same dir as current urls.py module  

app_name = 'pizzas' 

urlpatterns = [ 

    # Home page. 
    path('', views.index, name='index'),     
    # Show all pizzas
	path('pizzas/', views.pizzas, name='pizzas'), 
	# Details page for a single pizza
	path('pizzas/<int:pizza_id>', views.pizza, name='pizza'),   
] 
