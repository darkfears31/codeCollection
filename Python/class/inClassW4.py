def func_1(arg1: int, arg2: int) -> int:
    return arg1**arg2
print(func_1(arg2=5, arg1=5))
    


a1= int(input('Integer 1: '))
a2= int(input('Integer 2: '))
a3= int(input('Integer 3: '))
a4= int(input('Integer 4: '))

def func_2(*arg, **kvargs):
    prod = 1 
    if arg != {}:
        for val in arg:
            prod*=val
        return prod 
    if kvargs!={}:
        for val in kvargs.values():
            prod *= val 
    if arg and kvargs:
        return None
    return 0 
list = [a1,a2,a3,a4]
print(f'1. {func_2()}')
print(f'2. {func_2(a1)}')
print(f'3. {func_2(*arg: a1,a2,a3,a4)}')
print(f'4. {func_2(*list[2:])}')
dc = {a1,a2,a3,a4}
print(f'1. {func_2()}')
print(f'2. {func_2(a=a1)}')
print(f'3. {func_2(q1=a1,qa=a2,q3=a3,q4=a4)}')
print(f'1. {func_2(**dc)}')
