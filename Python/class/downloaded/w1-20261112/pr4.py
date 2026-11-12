"""
Example of using the for operator with else
"""
# x = range(1, 11, 3)
for o in range(1, 11, 4):
    if o % 10 == 0:
        break
else:
    print('The range does not contain a multiple of 10.')

