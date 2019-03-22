from django.shortcuts import render

# Create your views here.
def index(request): 

    """the home page for pizzeria""" 

    return render(request, 'pizzas/index.html') 
