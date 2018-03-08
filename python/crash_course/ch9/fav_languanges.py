""" Using python standard library. """

from collections import OrderedDict

fav_languages = OrderedDict()

fav_languages['jen'] = 'python'
fav_languages['sarah'] = 'c'
fav_languages['edward'] = 'ruby'

for name, language in fav_languages.items():
    print(name.title() + "'s favorite language is " +
        language.title() + ".")
