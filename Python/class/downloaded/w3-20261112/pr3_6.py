from random import randint, choice, uniform, sample
"""
1. Write a program that fills the dictionary with 100000 random integers
	from the range [100, 9999] (Use the string representation of the generated
	number as a key for the dictionary).  
   Calculate and Display:
   1. The number of elements, which is equal to 500;
   2. The number of unique values;
   3. The number of such values, in which the set of digits at even position
	  form palindrome; 
   4. Number of such values, in which digits are sorted in ascending or descending order; 
"""

# dct = {}
# for _ in range(100000):
#     if (x := str(randint(100, 9999))) in dct.keys():
#         dct[x] += 1
#     else:
#         dct[x] = 1

# 1.
# res_a = dct['500']

# 2.
# res_e = len(dct)  # len(dct.keys())

# 3.
# val = 0
# for key in dct:
#     for i in range(len(key) // 2):
#         if key[i] != key[-i]:
#             break
#     else:
#         val += dct[key]
# print(val)

# 4.

# val = 0
# for key in dct:
#     if key == ''.join(sorted(key)) or key == ''.join(sorted(key, reverse=True)):
#         val += dct[key]
# print(val)
