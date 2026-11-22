import threading as thr
from random import randint as rt
from time import perf_counter

def fill(a=1,b=100,row=20,col=1000000):
    funn =lambda a,b,c: [(rt(a,b), rt(a,b),rt(a,b)) for _ in range(col)]
    return [funn(a,b,col) for _ in range(row)]

def check(tr):
    a,b,c = sorted(tr)
    return a+b>c 

def st_func(ar):
    st = perf_counter()
    l_arr=[]
    for a in ar:
        l_arr.append(check(a))
    a = count = sum(check(tr) for tr in ar)
    print(f"Standart case: {perf_counter()-st}")

def th_func(ar):
    st = perf_counter()
    th_arr=[thr.Thread(target=check, args=(tr,)) for tr in ar]
    for th in th_arr:
        th.start()
    for th in th_arr:
        th.start()
    for th in th_arr:
        th.join()
    print(f"Thread    case: {perf_counter()-st}")

if __name__=='__main__':
    arr = [(rt(1,100), rt(1,100),rt(1,100)) for _ in range(1000)]
    print(arr[:5])
    st_func(arr)
    th_func(arr)
