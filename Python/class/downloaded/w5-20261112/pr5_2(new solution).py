""" 2. Write a function, which fills the file with random values from the range [1, 100]. The function
       must take six arguments: first and second arguments - values of start and end of the range;
       Third argument - the name of the file; Fourth argument - the number of rows in the file; Fifth
       argument - the number of values at the row; Six argument - the name of the file, where must be
       written the result. Use this function in the program and fill the "data2.in" file with 1000
       rows and 1000 values in the row. Read data from the file and fill a two-dimensional dictionary.
       Calculate the number of the most repeated value. In the first row in the result-file must be
       written such value and in other rows must be written outer key of the dictionary and the number
       of repetitions of the current value.    """
from opcode import opname
from random import randint as rInt
def func_2(a=1, b=100, file_in="data2.in", row=1000, col=1000, file_out="data2.out"):
    st = '\n'.join([
        ' '.join([ f'{rInt(a, b)}' for _ in range(col)])
        for _ in range(row)
    ])
    with open(file_in, 'w') as f_obj:
        f_obj.write(st)

    with open(file_in, 'r') as frd:
        arr = frd.read()
    arr = [[int(e) for e in row.split()] for row in arr.split('\n')]
    tmp = []
    for row in arr:
        tmp += row

    dc = {k: tmp.count(k) for k in range(a, b+1)}
    from pprint import pprint
    pprint(dc, indent=4)
    most_rep, arr0 = -1, []
    for k, v in dc.items():
        if v > most_rep:
            most_rep = v
            arr0 = [k]
        elif v == most_rep:
            arr0.append(k)
    print(most_rep)
    print(arr0)



    st = ''
    for val in arr0:
        st = f'value {val} was  mostly repeated {most_rep} times\n'
        for i, row in enumerate(arr):
            st += f'on row: {i} ==> value: {val}  ==> was repeated {row.count(val)} times\n'
        st += f'\n\n{50 * "*"}\n\n'

    with open(file_out, 'w') as f_obj:
        f_obj.write(st)


if __name__ == '__main__':
    func_2(a=10, b=20, row=10, file_in='newInp.in',file_out='newOut.out')
