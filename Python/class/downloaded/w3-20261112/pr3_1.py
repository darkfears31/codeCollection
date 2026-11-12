from random import randint, choice, uniform, sample


""" Write a program that fills the list with 10000 random integers from the range [100, 1000]. 
    Calculate and display the result for the received list:		
	1. The number of values, which belongs to range [150, 250]; 
	2. The number of values, which are multiples of 11 (use the division rule by 11) 
	3. The average value of such number, whose first and last digit are equal.   """
# arr = [randint(100, 10000) for _ in range(10000)]

# 1)
# arr_b = [numb for numb in arr if 150 <= numb <= 250]
# print(ar_2[:10])

# 2)
# ar_d = []
# for numb in arr:
#     odd = sum([int(n) for n in str(numb)[1::2]])
#     even = sum([int(n) for n in str(numb)[0::2]])
#     if (odd - even) % 11 == 0:
#         ar_d.append(numb)
# print(ar_d[:10], len(ar_d), sep='\n')

# 3)
# ar_v = [numb for numb in arr if str(numb)[0] == str(numb)[-1]]
# print(ar_v[:10])
# if ar_v:
#     print(f'Average value = {sum(ar_v) / len(ar_v)}')
# else:
#     print(f'Average value = {0}')