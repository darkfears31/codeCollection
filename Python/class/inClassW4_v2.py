from typing import Tuple
def dist(x: Tuple[int] ,y: Tuple[int]) -> float:
    return round( (y[1]-x[1])**2 + ((y[1]-x[1])**2), 2)

from random import randint as ri
def point_gen(f, range1=-50, range2=50):
    return (f(range1, range2), f(range1, range2))

arr = [ 
    (point_gen(ri), point_gen(ri))
    for _ in range(150)
]

fin_res = [
    dist(*obj)
    for obj in arr
]

print(fin_res[:10])
