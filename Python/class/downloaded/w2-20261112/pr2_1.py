""" Let's generate a string to solve specific problems over strings.
The corresponding string will be generated using the random and string modules """
import string as st
import random as rd
# a set of letters of the alphabet in lowercase and uppercase, numbers and some specific characters
dt = st.ascii_lowercase + st.ascii_uppercase + st.digits + '\\./+-*#@%^&_'

dt1 = ''
for _ in range(20):
    s = ''  # empty word
    # let's create a word with a random length (3-15)
    for _ in range(rd.randint(3, 15)):
        s += rd.choice(dt)  # add a random character to the word
    dt1 += s + ' '
# print(dt1) # output the generated set of words

# calculate the number of words after splitting a string into words
# sz = len(dt1.split())
# print(sz)

# Most string functions do not change the original string.
# print(dt1)
# print(dt1.split())
# print(dt1)

# Find the longest word in the sequence
ind, val, sz, rep = -1, '', -1, -1
for i, v in enumerate(dt1.split()):
    # print(f'{i}: {v}')
    if (a:=len(v)) > sz :
        sz = a
        val = v
        ind = i
        rep = 1
    elif a == sz: # if we found a word of the same length,
        rep += 1  # let's increase the number of such words
t = f'longist word:\n'
t += f'\tword: {val}\n'
t += f'\tlength: {sz}\n'
t += f'\tindex: {ind}\n'
t += f'\tcount: {rep}\n'
print(t)




