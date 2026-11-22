"""                          Lab - 8.7                          """

""" 2. The function `fill_file()` populates a file with random integer values 
       from the range [1, 100] (100 x 150,000).
       Read the data from the file. For each row, group the data into triplets and 
       determine how many of these triplets can form a triangle. Print the row number 
       where this count is the highest, along with the count itself.  """
from random import randint as rint
from time import perf_counter
from multiprocessing import Pool
from  concurrent.futures import ProcessPoolExecutor as ppe, ThreadPoolExecutor as tpe

def fill_file(fout, start=1, end=100, row=100, column=150000):
    """ The function fills the file with random values from the appropriate range. """
    with open(fout, 'w') as out:
        for i in range(row):
            row_val = [str(rint(start, end)) for _ in range(column)]
            out.write(' '.join(row_val) + '\n')

def is_triangle(x):
    """ The function checks whether it is possible to form a triangle from a triplet. """
    x = sorted(x)
    return 1 if x[0] + x[1] > x[2] else 0

def row_spliter(row):
    """ The function splits a single line of a file into a set of triplets.   """
    arr = [int(numb) for numb in row[:-1].split()]
    return [tuple(arr[3*i: 3*(i+1)]) for i in range(len(arr) // 3)]

def count_triangles(row):
    """ The function calculates the number of triangles from triplets. """
    return sum(is_triangle(triple) for triple in row_spliter(row))

def task_porcess(name, task_pool, rows):
    start = perf_counter()

    with task_pool(8) as pool:
        counts = list(pool.map(count_triangles, rows))

    row_index, max_count = max(enumerate(counts), key=lambda item: item[1])

    print(f"{name}: {perf_counter() - start:.4f} sec")
    print(f"max = {max_count}, row index = {row_index}\n")

def main():
    file = './num.in'
    fill_file(file)

    with open(file, 'r') as f:
       file_data = [line for line in f.read().split('\n')]

    task_porcess("multiprocessing.Pool", Pool, file_data)
    task_porcess(" ProcessPoolExecutor", ppe, file_data)
    task_porcess("  ThreadPoolExecutor", tpe, file_data)

if __name__ == '__main__':
    main()