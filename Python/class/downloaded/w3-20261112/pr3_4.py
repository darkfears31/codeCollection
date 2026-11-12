from random import randint, choice, uniform, sample
""" 6. Write a program that fills a 5x5 two-dimensional list with random real values from the range [0, 10]. 
       Calculate and display the result for the received list: 
		1.	The root from the sum of the squares of the elements from the main diagonal; 
		2.	The average value of such elements whose sum of indexes is even;   		 """

# arr = [[uniform(0, 10) for _ in range(5)] for _ in range(5)]
# print(arr)

# 1.
# res = sum([arr[i][i] ** 2 for i in range(5)]) ** 0.5
# print(res)

# 2.
# ar_g = [arr[i][j] for i in range(5) for j in range(5) if not (i+j) % 2]
# if ar_g:
#     print(f'Average value = {sum(ar_g) / len(ar_g)}')
# else:
#     print(f'Average value = {0}')