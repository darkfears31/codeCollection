"""
Write a code that calculates and prints the arithmetic mean of numbers 
from the interval [1000, 10000] such that the sum of their digits is a multiple of 7.

"""
res, co = 0, 0
for o in range(1_000, 10_000):
    tm = 0
    for i in str(o):
        tm += int(i)
    if not tm % 7:
        res += o
        co += 1

if co:
    print(f'Average is {round(res / co, 3)}'')
else:
    print('Such digits doe not exists')

