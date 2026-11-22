"""                          Lab - 8.5                          """

from time import perf_counter
from random import randint
from time import sleep

import threading as thr
import time

x = 0
N = 100000  

def inc_glob_value():
    global x
    temp = x
    time.sleep(0)
    x = temp + 1

def thread_function(n=N):
    for i in range(n):
        inc_glob_value()

def main():
    global x
    x = 0
    t1 = thr.Thread(target=thread_function)
    t2 = thr.Thread(target=thread_function)
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print(f"Expected: {2 * N}  =>  Received: {x}")

if __name__ == "__main__":
    for i in range(1, 6):
        main()
