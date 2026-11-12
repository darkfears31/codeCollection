# reading and writing in files.

#import json
#dct = {'k1': [1,2], 'k2': [3,4]}
#with open ('file.json', 'w') as f_out:
#    json.dump(dct, f_out)
#
#with open('file.json', 'r') as f_in:
#    dct1=json.load(f_in)
#
#print(dct1) 

# exceptions, error catching

#try:
#    x=int(input('Enter integer: '))
#    y=1/x
#except ZeroDivisionError:
#    y=0
#except ValueError:
#    y=0
#print(f"value of y is: {y}")

#try:
#    x=int(input('Enter integer: '))
#    y=1/x
#except:
#    y=0
#    print(f"error thrown")
#finally:
#    print(f'value of x is: {x}')
#print(f"value of y is: {y}")



# Random words with random size. 

#from random import choice as ch, randint as rint
#alfa = ['a', 'b', 'c', 'd', 'e', '.', ',', ':', ';', '!', '?', '4', '1', '2', '3']
#dc = {
#    "4": ['1de43', 'as124', 'a1521sad', 'ae4c'],
#    "5": ['a1b12', '3', 'aa', '4d', 'c', 'a']
#}
#
#n=100000
#st = ''.join([' ' if (c := ch(alfa)) in ['.', ',', ':', ';', '!', '?'] else c for _ in range(n)])
#words = st.split()
#
#def func(fun, path, st_data):
#    dc = {}
#    for wrd in st_data:
#        key=fun(wrd)
#        if key in dc.keys():
#            dc[key].append(wrd)
#        else:
#            dc[key] = [wrd]
#    st = '\n'.join([f'key: {key} ==> value: {value}' for key, value in dc.items()])
#    with open(path, mode='w') as f_obj:
#        f_obj.write(st)
#
#if __name__ == "__main__":
#    func(fun=len, path='data.in', st_data=words)
#    print(words[:10])

from random import randint as rint
def func(a=10, b=99, file_in="data2.in", row=1000, column=1000, col=1000, file_out="data2.out"):
    st = '\n'.join([
        ' '.join([f'{rint(a,b)}' for _ in range(col)])
        for _ in range(row)
    ])
    with open(file_in, 'r') as frd:
        arr = frd.read()
    arr.split('\n')
    arr = [row.split() for row in arr.split('\n')]
    tmp = []
    for row in arr:
        tmp += row

    dc = {key: tmp.count(key) for key in range (a, b+1)}
    most_rep, arr0 = -1, [] 
    for key, value in dc.items():
        if value > most_rep:
            most_rep = value
            arr0 = [(key, value)]
        elif value == most_rep:
            arr0.append((key, value))

    st = ''
    for val in arr0:
        st = f'Mostly was repeated {val}'
        for i, row in enumerate(arr):
            st += f'on row: {i} ==> value: {value} ==> was repeated {row.count(val)} times\n'
        st +=f'\n\n{50 * "*"}\n\n'

        with open(file_in, 'w') as f_obj:
            f_obj.write(st)


if __name__ == "__main__":
 func(a=10, b=20, row=10, file_in='data2.in', file_out='ragaca.out')
