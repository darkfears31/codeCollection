""" 2. Write a function that takes as a parameter an undefined number of values of the integer type 
       entered from the keyboard, and returns the result of multiplying these numbers.   """
def f2(*args, **kwargs):
    s = 1
    if args != ():     # if args represents the empty list
       for numb in args:
          s *= numb
    elif kwargs != {}:   # if kwargs represents the empty dictionary
       for numb in kwargs.values():
          s *= numb
    else:
       s = 0
    return s



a = int(input('number 1: '))
b = int(input('number 2: '))
c = int(input('number 3: '))

dc ={'x':a, 'y' : b, 'z' : c}
print(dc)


print(f"there works parameter: *args")
print(f"  function without    parameter: {f2()}")
print(f"  function with one parameter: {f2(a)}")
print(f"  function with two parameter: {f2(a, b)}")
print(f"function with three parameter: {f2(a,b,c)}")
print(f"function with three parameter: {f2(*(a,b,c))}")
print(f"there works parameter: **kwargs")
print(f"  function without    parameter: {f2()}")
print(f"  function with one parameter: {f2(x=a)}")
print(f"  function with two parameter: {f2(z=a, x=b)}")
print(f"function with three parameter: {f2(k=a,y=b,z=c)}")
print(f"function with three parameter: {f2(**dc)}")