#!/usr/bin/env python3
# https://chrisyeh96.github.io/2017/08/08/definitive-guide-python-imports.html
import sys
import pkgutil
# import statements search through the list of paths in sys.path
print("***sys.path: \n")
print(sys.path)
#This list of built-in modules is installation-dependent and can be found in 
# sys.builtin_module_names (
print("***Built-in Module Names: \n")
print(sys.builtin_module_names)

# The function pkgutil.iter_modules (Python 2 and 3) can be used to get a list 
# of all importable modules from a given path:
search_path = ['.'] # set to None to see all modules importable from sys.path
all_modules = [x[1] for x in pkgutil.iter_modules(path=search_path)]
print("***All importable Modules from current path : \n")
print(all_modules)
