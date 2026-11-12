# divisible by three
x = int(input("Enter Integer: "))
print(f'Type of x= {type(x)}')
if x%3==0 :
    print('Divisible by three')
else:
    print("Isn't divisible by three")

#for loop
for i in range(1, 11, 2):
    if i%2 == 0:
        break
else:
    print(f'inside range we have no even digits')

# Calculator
num1 = int(input("Integer 1: "))
num2 = int(input("Integer 2: "))
op = input("Arithmetic operator: ")
match op:
    case '+':
        print(f'{num1}+{num2}={num1+num2}')
    case '-':
        print(f'{num1}-{num2}={num1-num2}')
    case '/':
        print(f'{num1}/{num2}={num1/num2}')
    case '*':
        print(f'{num1}*{num2}={num1*num2}')
    case _:
        pass

if op in '+-/*':
    print(f"{op} is arithmetic operator")
else:
    print(f'{op} isnt arithmetic operator')

sum, co = 0,0
for num in range(1000, 10001):
    s=0
    for i in str(num):
        s+=int(i)
    if s%7 != 0:
        sum +=num
        co+=1
if co:
    print(f'Average is {sum/co}')
else:
    print('such number does not exist')
