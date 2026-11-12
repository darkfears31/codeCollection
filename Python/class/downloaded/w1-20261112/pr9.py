"""
Write a program that determines whether the values at even positions in 
a given integer are sorted in descending order.
"""
x = 9591966243344
st = str(x)
sz = len(st)
b = True
for o in range(0,sz-2,2):
    if st[o] < st[o+2]:
        b = False
        break
if b:
    print('The numbers in the even positions are arranged in descending order.')
else:
    print('Numbers in even positions not sorted in descending order')