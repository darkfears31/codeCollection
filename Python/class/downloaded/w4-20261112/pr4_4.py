""" 4. Write a function in which takes as the first parameter the function, and as a necessary
       parameter takes the fourth and fifth parameters.
       (1) Inside a function, define a function generator that generates the list of random numbers
	       whose size is equal to the fourth parameter of outer function and random numbers belong to
		   the range defined by the second and third value of the outer function. The number of such
		   lists must be equal to the fifth parameter of uoter function. The number of such lists must
		   be equal to the fifth parameter of the outer function.
	   (2) The function passed as the first parameter must change the value of each number in the list
	       to a squared value of that value
       (3) Using this set, create and fill the dictionary based on the following principle: use the number
	       of digits 1 in the value as the key, and insert this value into the set to this key
       (4) The outer function must display all key and the number of elements in the set of that key
       (5) When using the function, transfer the first parameter via the lambda function.   """
# def f4(f, a, b, *, n1, n2):
#     def gen(_f, _a, _b, _n1, _n2):
#         for _ in range(_n2):
#             yield [_f(ob) for ob in sample(range(_a, _b+1), _n1)]
#     ar = []
#     for row in gen(f, a, b, n1, n2):
#         ar += row
#
#     d = {}
#     for numb in ar:
#         key = (str(numb)).count('1')
#         if key in d.keys():
#             d[key].append(numb)
#         else:
#             d[key] = [numb] # d[key] = []; d[key].append(numb)
#
#     for key, value in d.items():
#         print(f'key = {key},  len(value) = {len(value)}')
#
# f4(lambda x: x ** 2,  1, 100000, n1=500, n2=1000)