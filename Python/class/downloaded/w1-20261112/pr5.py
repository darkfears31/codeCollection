"""Write a code (calculator) that calculates and prints the result of the arithmetic operation corresponding to two integers and an arithmetic operation symbol entered from the keyboard.
."""

x = int(input("Enter an integer 1: "))
y = int(input("Enter an integer 2: "))
ch = input("Enter an arithmetic operation : ").strip(' ')
res = None
match ch:
    case '+':
        res = x + y
    case '-':
        res = x - y
    case '*':
        res = x * y
    case '/':
        res = x / y
    case _:
        print("The calculator cannot perform such a calculation.")

if res == None:
    print('The calculator could not work.')
else:
    print(f'res = {res}')

