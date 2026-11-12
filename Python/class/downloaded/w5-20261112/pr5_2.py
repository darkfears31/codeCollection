""" 2. Write a function, which fills the file with random values from the range [1, 100]. The function
       must take six arguments: first and second arguments - values of start and end of the range;
       Third argument - the name of the file; Fourth argument - the number of rows in the file; Fifth
       argument - the number of values at the row; Six argument - the name of the file, where must be
       written the result. Use this function in the program and fill the "data2.in" file with 1000
       rows and 1000 values in the row. Read data from the file and fill a two-dimensional dictionary.
       Calculate the number of the most repeated value. In the first row in the result-file must be
       written such value and in other rows must be written outer key of the dictionary and the number
       of repetitions of the current value.    """


def func_2(st_ran, en_ran, file1, row, column, file2):
    with open(file1, 'w') as f_out:
        for _ in range(row):
            ar = [str(rint(st_ran, en_ran)) for _ in range(column)]
            ar = ' '.join(ar)
            f_out.write(ar + '\n')
        del ar

    tmp_dict = {}
    with open(file1, 'r') as f_in:
        ar = f_in.readlines()

    for numb in ar:
        numb = numb[:-1]
        st = numb.split()
        for n in st:
            if n in tmp_dict.keys():
                tmp_dict[n] += 1
            else:
                tmp_dict[n] = 1

    Max, Value = 0, 0
    for key in tmp_dict.keys():
        if Max < tmp_dict[key]:
            Max = tmp_dict[key]
            Value = key

    with open(file2, 'w') as f_out:
        f_out.write(f"value of element {str(Value)}, number of repetition {str(Max)} \n")
        for index in range(len(ar)):
            a = (ar[index][:-1]).split()
            f_out.write(f"row = {str(index)}, count = {str(a.count(str(Value)))}\n")

if __name__ == '__main__':
    func_2(1, 100, "data2.in", 1000, 1000, "data2.out")
