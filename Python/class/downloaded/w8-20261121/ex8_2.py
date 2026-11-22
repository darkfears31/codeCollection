"""                          Lab - 8.2                          """

from time import perf_counter
import threading as thr
from ex8_1 import *
""" Using a thread-based technology, populate a 2-dimensional 
    10x1_000_000 list with random values, and compare the time
    spent on this task in with the time from previous tasks.  """

def th_fill(func=fill_row, row=10):
    ''' The function populates a list with 10 elements using thread-based technology. '''
    st = perf_counter()
    th_arr = [thr.Thread(target=fill_row) for _ in range(row)]
    for th in th_arr:
        th.start()
    for th in th_arr:
        th.join()
    print(f'time         (with thread): {perf_counter() - st: .7f}')


if __name__ == '__main__':
    st_fill()
    th_fill()
    pr_fill()



