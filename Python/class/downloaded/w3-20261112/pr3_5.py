from random import randint, choice, uniform, sample
""" Write a program that fills a 1000x100 two-dimensional list with random unique values from the range [1, 500].
    Calculate and display the result for the received list: 
	1.	The number of the most repeated values; 
	2.	The number of such rows, in which the maximum value is equal to 450;
	3.	The number of columns and rows, in which the minimum value is equal to 10.    """
arr = [sample(range(1, 501), 100) for _ in range(1000)]
# 1.
# ar_1 = 501 * [0]
# for i in range(1000):
#     for j in range(100):
#         ar_1[ arr[i][j] ] += 1
# val, Max = 0, max(ar_1)
# for i in range(1, 501):
#     if ar_1[i] == Max:
#         val = i
#         break
# print(f'number {val} was repeated {Max} times')

# 2.
# ssum = sum([num ** 2 for num in arr[19]])
# prod = 1
# for num in arr[50]:
#     prod *= num
# print(ssum - prod)

# 3.
# min_r = [1 for ob in arr if min(ob) == 10]
# min_c = [1 for j in range(100) if min([arr[i][j] for i in range(1000)]) == 10]
# print(len(min_r) + len(min_c))
#
# # 2 the same task was solved using dict
# dct = {}
# for i in range(1000):
#     for j in range(100):
#         if (x := arr7[i][j]) in dct.keys():
#             dct[x] += 1
#         else:
#             dct[x] = 1
#
# mmax, val = max(dct.values()), 0
# for key in dct:
#     if dct[key] == mmax:
#         val = key
#         break
