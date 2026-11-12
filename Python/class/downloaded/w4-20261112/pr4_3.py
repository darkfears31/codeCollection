""" 3. Write a function that takes three necessary parameters.
       (1) Inside a function, define a function generator that generates square of a random number
	       from a range that is determined using the first two parameters of the external function.
		   The number of such values must be determined using the third parameter of the external function.
       (2) Use the inner function to obtain the set of the generated values. Into the set, count the
	       number of the values whose sum of digits is multiples of 7.    """
from random import randint as rInt, sample
# def ff(*, a, b, n):
#     def gen(a1, a2, n1):
#         for _ in range(n1):
#             yield (rInt(a1, a2)) ** 2
#
#     print(list(gen(a, b, n))[:20])
#     count = 1
#     for ob in gen(a, b, n):
#         if not sum([int(x) for x in str(ob)]) % 7:
#             count += 1
#     return count
# print(ff(a=1, b=100, n=1000))