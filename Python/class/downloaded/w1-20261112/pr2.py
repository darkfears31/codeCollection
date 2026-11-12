"""
Write a program that determines whether a whole number entered from the keyboard is divisible by three.
""""
x = input("Enter an integer: ")
print(type(x))
x = int(x)
print(type(x))
if x % 3 == 0:
    print(f'{x} is a multiple of 3')
elif x % 3 == 1:
    print(f'Dividing {x} by 3 leaves a remainder of 1')
else:
    print(f'Dividing {x} by 3 leaves a remainder of 2')