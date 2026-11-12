from random import randint, choice, uniform, sample
""" Write a program that fills the list with 100000 random integers from the range [100000, 1000000]. 
    Calculate and display the result for the received list:
	1.	The sum of such 500 numbers, in which the sum of digits is even, but the last digit different 
		than 3 or 7;
	2.	From 2000 random integers, the number of integers that are odd and, moreover, the sum of the 
		digits on the odd index is greater than the sum of the digits on the even index;
	3.	The average value of numbers, in which the sequence of digits at the even index are represented 
		in descending order;  """

# arr = [randint(100000, 1000000) for _ in range(100000)]

# 1.
# ar_b, count = [], 0
# for numb in arr:
#     if count == 500:
#         break
#     if sum([int(n) for n in str(numb)]) % 2 == 0 and str(numb)[-1] not in ['3', '7']:
#         ar_b.append(numb)
#         count += 1
# print(sum(ar_b))

# 2.
# ar_d = []
# for _ in range(2000):
#     numb = choice(arr)
#     odd = sum([int(n) for n in str(numb)[1::2]])
#     even = sum([int(n) for n in str(numb)[0::2]])
#     if numb % 2 == 1 and odd > even:
#         ar_d.append(numb)
# print(len(ar_d))

# 3.
# ar_v = []
# for numb in arr:
#     ar = [int(n) for n in str(numb)[::2]]
#     if ar == sorted(ar, reverse=True):
#         ar_v.append(numb)
# print(ar_v[:10])
# if not len(ar_v):
#     print(f'Average value = {0}')
# else:
#     print(f'Average value = {sum(ar_v) / len(ar_v)}')
