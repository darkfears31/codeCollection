""" Let's generate a string to solve specific problems over strings.
The corresponding string will be generated using the random and string modules """
import string as st
import random as rd
dt = st.ascii_lowercase  + st.digits

dt1 = ''
for _ in range(1_000_000):
    s = ''  # empty word
    # let's create a word with a random length (3-8)
    for _ in range(rd.randint(3, 8)):
        s += rd.choice(dt)
    dt1 += s + ' '
# print(dt1)  # output the generated set of words

# let's remove the letter characters from the generated string, leaving only numeric values
# in order, and calculate the time it takes to complete the corresponding activity.

""" Let's compare the time it takes to extract alphabetic characters
    from a string when using standard and regular expressions. """
import time

# Removing alphabetic characters from a string using the standard approach
start = time.time() # start time
st_arr = ''
pr = ' '
for ch in dt1:
    if ch.isdigit():
        pr = ch
    else:
        if pr.isdigit():
            pr = ' '
        else:
            continue
    st_arr += pr
print(time.time() - start)

# Extracting alphabetic characters from a string using regular expressions
import re
start = time.time() # start time
patt = r'\d+' # regular expressions
re_arr = ' '.join(re.findall(patt, dt1))
print(time.time() - start)

# output the final set
# print(st_arr, re_arr, sep='\n')
