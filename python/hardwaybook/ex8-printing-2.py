formatter = "%r %r %r %r"

print formatter % (1, 2, 3, 4)
print formatter % ("one", "two", "three", "four")
# These are booleans
print formatter % (True, False, False, True)
print formatter % (formatter, formatter, formatter, formatter)
# the raw formatter automatically selects double quotes for display
#if there are single quotes in the string
print formatter % (
    "I had this thing.",
    "That you could've type up right.",
    "But it didn't sing.",
    "So I said goodnight."
    )
