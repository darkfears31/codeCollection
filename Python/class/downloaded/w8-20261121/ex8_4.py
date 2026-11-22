"""                          Lab - 8.4                          """

from time import perf_counter
from ex8_3 import *
from  concurrent.futures import ProcessPoolExecutor as ppe, ThreadPoolExecutor as tpe
from random import uniform
""" Using a concurrent.future technology, populate a 2-dimensional 
    10x1_000_000 list with random values, and compare the
    time spent on this task in with the time from previous tasks.  """

def ppe_fill(func=fill_row, row=10, col=1_000_000):
    ''' The function populates a list with 10 elements using ProcessPoolExecutor. '''
    st = perf_counter()
    with ppe(max_workers=6) as PPE:
        ppe_arr = list(PPE.map(func, [col] * row))
    print(f'time (ProcessPoolExecutor): {perf_counter() - st: .7f}')

def tpe_fill(func=fill_row, row=10, col=1_000_000):
    ''' The function populates a list with 10 elements using ThreadPoolExecutor. '''
    st = perf_counter()
    with tpe(max_workers=6) as TPE:
        tpe_arr = list(TPE.map(func, [col] * row))
    print(f'time  (ThreadPoolExecutor): {perf_counter() - st: .7f}')


if __name__ == '__main__':
    st_fill()
    th_fill()
    pr_fill()
    pl_fill()
    tpe_fill()
    ppe_fill()