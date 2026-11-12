"""
Rewrite the previous task using the match operator."""
x = int(input("Enter an integer: "))
match x % 3 :
    case 1:
        print(f'Dividing {x} by 3 leaves a remainder of 1')
    case 2:
        print(f'Dividing {x} by 3 leaves a remainder of 2')
    case _ :
        print(f'{x} is a multiple of 3')