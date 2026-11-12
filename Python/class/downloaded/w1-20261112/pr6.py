"""
Write a code that calculates and prints the product of all the cubes of 
the integers divisible by 7 taken from the interval [20, 50].
"""
a, b, c = 20, 50, 7
for o in range(a, b):
    if not o % 7:
        t = o
        a = 1
        for o1 in range(t, b, c):
            a *= o1 ** 3
        break


print(f'res = {a}')