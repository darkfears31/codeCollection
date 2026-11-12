""" 3. A triangle can be classified based on the lengths of its sides as equilateral, isosceles or
       scalene. All 3 sides of an equilateral triangle have the same length. An isosceles triangle has
       two sides that are the same length, and a third side that is a different length. If all the
       sides have different lengths, then the triangle is scalene.

       Write a program that fills file "data3.in" with random values from the range [1, 1000] with 1000
       rows and 1500 values at the row. Write a function, which take one argument: the name of the data
       file. The function must read data from the file, at the row group all neighbor three values as
       tuple object and calculate for such numbers exist or not an appropriate triangle. If such a
       triangle exists this tuple must be inserted into the set of elements at the dictionary key with
       the name of the type of triangle. If such a triangle does not exist this tuple must be inserted
       into the set of elements at the dictionary key "other".

       The function as a result must return the dictionary. Use this function in the program and display
       the key of the current dictionary and the number of elements at that key.   """

from pr5_2 import func_2
def f3(file):
    arr = None
    with open(file, 'r') as inp:
        arr = inp.readlines()
    # Let define the corresponding keys of the rectangle type
    # type-0 = other
    # type-1 = Equilateral triangle
    # type-2 = Isosceles triangle
    # type-3 = A right triangle
    # type-4 = Ordinary triangle

    dct = {'type-' + str(i): [] for i in range(5)}

    for obj in arr:

        numbers = [int(numb) for numb in (obj[:-1]).split()]

        numbers = [tuple(sorted(numbers[3 * i: 3 * (i + 1)])) for i in range(len(numbers) // 3)]

        for numb in numbers:

            if numb[0] + numb[1] <= numb[2]:

                dct['type-0'].append(numb)

            elif numb[0] == numb[1] == numb[2]:

                dct['type-1'].append(numb)

            elif numb[0] == numb[1] or numb[1] == numb[2]:

                dct['type-2'].append(numb)

            elif numb[0] ** 2 + numb[1] ** 2 == numb[2] ** 2:

                dct['type-3'].append(numb)
            else:

                dct['type-4'].append(numb)

    print("After classification, the triangles were redistributed as follows:")
    for key, value in dct.items():
        print(f"{key} : {len(value)}")

    print("The following number of unique triangles were fixed on the keys:")
    for key, value in dct.items():
        print(f"{key} : {len(set(value))}")

if __name__ == '__main__':

    file3_in, file3_result = 'file3.in', 'file3.result'
    range_start, range_end = 1, 100
    row_count, col_count = 1000, 1500

    func_2(range_start, range_end, file3_in, row_count, col_count, file3_result)
    f3(file3_in)