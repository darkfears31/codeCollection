"""
Write a code that calculates and prints the average of all numbers from 
the interval [70, 190] that end in 3, and those whose remainder when divided by 7 is 3.
"""
a = [1, 2, 3]
print(sum(a))

sum, co = 0, 0
for o in range(70, 191):
    if str(o)[-1] == '3' or o % 7 == 3:
        sum += o
        co += 1

if co:
    print(f'Average is {sum / co}')
else:
    print('Such digits doe not exists')



