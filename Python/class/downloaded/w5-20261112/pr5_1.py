"""          Lab - 5            """
from random import choice as ch, randint as rint

alfa = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1',
        '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', ':', ';', '!', '?', ' ']
""" 1. From the set alfa create a new string with 1000000 characters. During the string creation 
       process characters '.', ',', ':', ';', '!' must be changed to a character space. Write a 
       function, which takes three arguments: first - function (this argument must choose values 
       with a specific option (for example value with length 5)), second - file name (argument, where 
       must be written result), third - string value (argument, which must be used for processing). 
       dct = {}

       """

N = 1000000
st = ''.join([' ' if (c := ch(alfa)) in ['.', ',', ':', ';', '!', '?'] else c for _ in range(N)])
words = st.split()


def f1(func, f_out, lst) :
    d = {}
    for word in lst:
        if (key := func(word)) in d.keys():
            d[key].append(word)
        else:
            d[key] = [word]

    # Let's write the dictionary data to a file.
    with open(f_out, 'w') as out:
        for key in d.keys():
            out.write(f"{key} : {' '.join(d[key])}\n")

    """ A dictionary can also be created using the `collections.defaultdict` object. 
        This can be done with the following code snippet:

        from collections import defaultdict
        d1 = defaultdict(list)  # By specifying `list` as a parameter, a list will be automatically created for the key.
        for word in words:
            d1[func(word)].append(word)     # It is not necessary to check here whether we had a list for the key.

        This approach works faster than usual.        """






















