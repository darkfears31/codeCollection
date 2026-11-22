"""                          Lab - 8.3                          """

from ex8_2 import *
from random import uniform
""" Using a process_pool-based technology, populate a 2-dimensional 
    10x1_000_000 list with random values, and compare the
    time spent on this task in with the time from previous tasks.  """

def pl_fill(func=fill_row, row=10, col=1_000_000):
    ''' The function populates a list with 10 elements using process_pool-based technology. '''
    st = perf_counter()
    with Pool(processes=6) as pool:
        pl_arr = pool.map(func, [col] * row)
    print(f'time   (with process pool): {perf_counter() - st: .7f}')


if __name__ == '__main__':
    st_fill()
    th_fill()
    pr_fill()
    pl_fill()



