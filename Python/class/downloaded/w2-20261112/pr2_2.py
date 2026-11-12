""" Let's generate a string to solve specific problems over strings.
The corresponding string will be generated using the random and string modules """
import string as st
import random as rd
dt = st.ascii_lowercase  + st.digits

dt1 = ''
for _ in range(100_000):
    s = '' # empty word
    # let's create a word with a random length (3-8)
    for _ in range(rd.randint(3, 8)):
        s += rd.choice(dt)  # add a random character to the word
    dt1 += s + ' '
# print(dt1) # output the generated set of words

# let's remove the letter characters from the generated string, leaving only numeric values
# in order, and calculate the time it takes to complete the corresponding activity.
import time
start = time.time()  # start time
st_arr = ''
for i in dt1:
    if i.isdigit():
        st_arr += i  # If the current character is a digit, let's keep its value.
    else:
        st_arr += ' ' # if not, let's replace it with a space character
    # the ternary operator (if ... else) below does the same
    # st_arr = i if i.isdigit() else ' '
print(time.time() - start) # end time
print(st_arr)  # output the final set

# using list comprehension let's remove space character from the final set.
# using the comprehension (generator) of the list, remove the space character from the final set
# st_arr1 = [ int(i) for i in st_arr.split() if len(i) ]
# print(st_arr1) # output the final set
# st_arr1 = [ int(i) for i in st_arr.split() if len(i) == 2 ] # length of word is 2
# print(st_arr1) # output the final set

# the same without generator
# arr = []
# for i in st_arr.split():
#     if len(i):
#         arr.append(i)