''' 5. Write a function that calculates the distance between two points in a plane using the
       formula 𝑑 = sqrt((𝑥2 − 𝑥1)^2 + (𝑦2 − 𝑦1)^2). Generate 150 random pairs (x1,y1),(x2,y2),
       with each coordinate in [−50, 50]. Calculate the distance for each pair of points.
       Print the points with the smallest distance between them. '''
# from collections import namedtuple
# point = namedtuple("Point", ["x_coord", "y_coord"])
from typing import Tuple

from jedi.inference.references import find_references


def dist(x: Tuple[int], y: Tuple[int]) -> float:
    return round( ((y[0]-x[0]) ** 2 + (y[1]-x[1]) ** 2) ** 0.5, 2)

from random import randint as ri
def p_gen(f, a=-50, b=50):
    return (f(a, b), f(a, b))

arr = [
    (p_gen(ri), p_gen(ri))
    for _ in range(150)
]
print(arr[0])

# fin_res = list(map(dist, arr))
fin_res = [
    dist(*obj)
    for obj in arr
]
mmin = min(fin_res)
ind = fin_res.index(mmin)
print(f'points: {arr[ind]}')
print(f'  dist: {mmin}')


