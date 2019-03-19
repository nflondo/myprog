from django.shortcuts import render

# Create your views here.
def index(request):
	"""the home page for learning log"""
	return render(request, 'meal_plan_app/index.html')
