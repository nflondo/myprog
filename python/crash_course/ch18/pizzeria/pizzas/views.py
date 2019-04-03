from django.shortcuts import render

from .models import Pizza
# Create your views here.
def index(request): 
    """the home page for pizzeria""" 
    return render(request, 'pizzas/index.html') 
    
def pizzas(request):
	"""Show all pizzas."""
	pizzas = Pizza.objects.order_by('date_added')
	context = {'pizzas': pizzas}
	return render(request, 'pizzas/pizzas.html', context)
	
def pizza(request, pizza_id):
	"""Show a single pizza and all its entries."""
	pizza = Pizza.objects.get(id=pizza_id)
	toppings = pizza.topping_set.all()
	context = {'pizza': pizza, 'toppings': toppings}
	return render(request, 'pizzas/pizza.html', context)
