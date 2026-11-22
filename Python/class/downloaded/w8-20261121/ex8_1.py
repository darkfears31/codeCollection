"""                          Lab - 8.1                          """

from time import perf_counter
from multiprocessing import Process, Pool
from random import uniform
""" Using a standard approach and process-based technology, populate
    a 2-dimensional 10x1_000_000 list with random values, and compare
    the time spent on this task in both cases. """
def fill_row(a_min=10, b_max=99, col=1_000_000):
    ''' The function creates and returns an array with 1_000_000 elements. '''
    return  [uniform(a_min, b_max) for _ in range(col)]


def st_fill(func=fill_row, row=10):
    ''' The function populates the list with 50 elements. '''
    st = perf_counter()
    arr = [ func() for _ in range(row)]
    print(f'time       (standard case): {perf_counter() - st: .7f}')


def pr_fill(func=fill_row, row=10):
    ''' The function populates a list with 10 elements using process-based technology. '''
    st = perf_counter()
    pr_arr = [Process(target=fill_row) for _ in range(row)]
    for pr in pr_arr:
        pr.start()
    for pr in pr_arr:
        pr.join()
    print(f'time        (with process): {perf_counter() - st: .7f}')


if __name__ == '__main__':
    st_fill()
    pr_fill()



