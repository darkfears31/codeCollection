#----------------------------------------------------
#x=1000
#for j in range(1, 10):
#    k=x%j
#    match k: 
#        case 1:
#            print(f"{x}%{j}={k}")
#        case 2:
#            print(f"{x}%{j}={k}")
#        case 3:
#            print(f"{x}%{j}={k}")
#        case 4:
#            print(f"{x}%{j}={k}")
#        case 5:
#            print(f"{x}%{j}={k}")
#        case 6:
#            print(f"{x}%{j}={k}")
#        case 7:
#            print(f"{x}%{j}={k}")
#        case 8:
#            print(f"{x}%{j}={k}")
#        case 9:
#            print(f"{x}%{j}={k}")
#        case _ :
#            print("None of them.\n")
#----------------------------------------------------

#----------------------------------------------------
#st = 'string'
#map=[]
#map=[f"abc: {s}" for s in st]
#for _ in map:
#    print(_)
#----------------------------------------------------


#----------------------------------------------------
#   Write a program that calculates 
#   for E (-1)^n•sin(nπ+1)/(2n-1)π
#import math as m
#end = int(input("Enter till which number Sum should calculate: "))
#sum =0
#i=0
#while i<=end:
#    sum+=((-1)**i) * m.sin(i*m.pi+1)/((2*i-1)*m.pi)
#    i+=1
#print(f"Sum from 0 to {end} is: {sum}")
#----------------------------------------------------

#----------------------------------------------------
#enumerate
#for i, ch in enumerate('python123'):
#    print(str(i)+' '+ch)
#----------------------------------------------------

#----------------------------------------------------
#adding stuff to list.
#arr = []
#for ch in 'python123':
#    arr.append(ch)
#print(arr)
#arr.append(['bac', 'cad', 'kad', [1,2,3]])
#print(arr)
#for i in arr:
#    if type(i) is list:
#        for k in i:
#            if type(k) is list:
#                for j in k:
#                    print(j)
#            else:
#                print(k)
#    else:
#        print(i)
#----------------------------------------------------

#----------------------------------------------------
#Nested list recursive reading.
#def show(listI):
#    for i in listI:
#        if type(i) is list:
#            show(i)
#        else:
#            print(i)
#
#arr = []
#for ch in 'pythasd213asd':
#    arr.append(ch)
#arr.append(['bat', 'catt', 'triple', [1,2,3]])
#show(arr)
#----------------------------------------------------

#----------------------------------------------------
#dict - same as unordered_map
#d = { 'a':1, 'b': 2,'c':3,'d':4, } 
#for key in d:
#    print(f'key= {key}, value= {d[key]}')
#
#d={key: key*3 for key in range(1, len(d))}
#print('\n')
#for key in d:
#    print(f'key= {key}, value= {d[key]}')
#----------------------------------------------------

#----------------------------------------------------
#tuple
#t= ('abc', 123, (1,2,3,'asd'), [5,6,7,8,'asd'], 'abc')
#----------------------------------------------------

#----------------------------------------------------
#set
#s1=set((1,2,3,4,5,6))
#s1.update(set('f'))
#s1.update(set(('a','b','c','d')))
#s1.update([1,3,4])
#print(type(s1))
#print(s1)
#s1.add(('ragaca'))
#print(s1)
#----------------------------------------------------

#----------------------------------------------------
# namedtuple
#from collections import namedtuple as nt
#
#Point = nt('Point', ['x', 'y'])
#var = Point(5,10)
#print(var[0]*var[1])
#print(var.x*var.y )
#x,y=var #unpacked
#print(x*y)
#----------------------------------------------------

#----------------------------------------------------
#counter - know how many times object was repeated in any
# iterable container    
#from random import randint as rt
#from collections import Counter
#
#arr = [rt(1,10) for _ in range(1000)]
#cnt = Counter(arr)
#for key, value in sorted(cnt.items()):
#    print(f"value {key} was repeated {value} times\n")
#print(type(cnt))
#print(cnt)
#----------------------------------------------------

#----------------------------------------------------
# setdefault - It takes a list of pairs and builds
# a dict where each key points to a list of all the 
# values that came with it.

#from random import randint as rt,  choice
#from collections import defaultdict as dd
#
#names = ['one', 'two', 'three', 'four', 'five']
#array = [(choice(names), rt(1,50)) for _ in range(1,250)]
#d1=dd(list)
#for key, val in array:
#    d1[key].append(val)
#
#d2={}
#for key, val in array:
#    d2.setdefault(key,[]).append(val)
#print(f"Array:{array}")
#print(f"D1:{d1}")
#print(f"D2:{d2}")
#----------------------------------------------------

#----------------------------------------------------
# Searching in file with regex.
#import re
#found = False
#with open("re_data.in", "r") as file:
#    for line in file:
#        if re.match(r"ID: [A-Z][A-Z]_\d{5}$", line):
#            print(line)
#            found = True
#if not found:
#    print("Not found.\n")
#----------------------------------------------------

#----------------------------------------------------
# Searching in file with regex.
#import re 
#found = False
#with open("re_data.in", "r") as file:
#    for line in file:
#        if re.match(r"\+995-5\d{2}-\d{3}-\d{3}$", line):
#            print(line)
#            found=True
#if not found:
#    print("Not Found.\n")
#----------------------------------------------------

#----------------------------------------------------
"""
Library records. Define a namedtuple named Book with attributes id, genre, pages.

id is a unique code like Bk_0042 (four digits).
genre has 12 possible values (gn_01 to gn_12).
pages is an integer in [40, 1200].

(1) Generate 2,500 random records. 
(2) Use defaultdict to group them by genre, then compute the average and total pages per genre. 
(3) Find the genre with the fewest books. Print all genres in case of a tie.
"""
#from random import randint as rt
#from collections import defaultdict as dd, namedtuple as nt 
#Book = nt("Book", ["Bid","genre","pages"])
#books=[]
#for i in range (1, 2501):
#    Bid=f"Bk_{i:04d}"
#    genre=f"gn_{rt(1,12):02d}"
#    pages=rt(40,1200)
#    books.append(Book(Bid, genre, pages))
#print(len(books))
#
#sorted = dd(list)
#for book in books:
#    sorted[book.genre].append(book)
#print(len(sorted))
#for key, pages in sorted.items():
#    avg=0
#    for book in sorted[key]:
#        avg+=book.pages
#    print(f"Total Pages {key}: {avg}")
#    print(avg/len(sorted[key]))
#
#fewest = min(len(v) for v in sorted.values())
#tied = [key for key, val in sorted.items() if len(val)==fewest]
#print(f"Fewest books: {fewest}, genre(s): {', '.join(tied)}")
#----------------------------------------------------

#----------------------------------------------------
"""
Student grades. Define Grade = namedtuple('Grade', ['student', 'subject', 'score']). 
Generate 800 records with 40 students, 6 subjects, and scores as real numbers in [0, 100]. 
(1) Group by student and print each student’s average. 
(2) Find the best and worst student.
(3) Print students whose average is above the overall average.
"""
#import random as rd
#from collections import namedtuple as nt, defaultdict as dd
#
#Grade = nt('Grade', ['student', 'subject', 'score'])
#grades = [Grade(student=f"st_{rd.randint(1,40):02d}", subject=f"sb_{rd.randint(1,6):01d}", score=rd.uniform(1,100)) for _ in range(800)]
#print(len(grades))
#
#gradesSorted=dd(list)
#for student in grades:
#    gradesSorted[student.student].append(student)
#print(len(gradesSorted))
#
#averages = {}
#for key, val in gradesSorted.items():
#    total=0
#    for info in val:
#        total+=info.score
#    print(f"ID: {key}")
#    print(f"Total score: {total}")
#    print(f"Average score: {total/len(val)}")
#    averages[key]=(total/len(val))
#
#bestS = max(averages, key=averages.get)
#worstS = min(averages, key=averages.get)
#print(f"Best student: {bestS} id ")
#print(f"Worst student: {worstS} id")
#
#asboluteAvg=0 
#for avg in averages.values():
#    asboluteAvg+=avg
#asboluteAvg/=len(averages.values())
#print(f"Asolute Average: {asboluteAvg}")
#
#i=0
#for student, avg in averages.items():
#    if avg>asboluteAvg:
#        print(student)
#        i+=1
#print(i)
#----------------------------------------------------

#----------------------------------------------------
"""
    Warehouse. Define Item with sku, warehouse, quantity,
    where the warehouse is one of 8 codes. Generate 5,000 records. 
    Use defaultdict(int) to total the quantity per warehouse,
    then print the warehouses sorted from highest to lowest.
"""
#import random as rd
#from collections import namedtuple as nt, defaultdict as dd
#
#warehouse = nt("warehouse", ["sku","id","quantity"])
#warehouses = [warehouse(sku=f"sku_{_:04d}", id=rd.randint(1,8), quantity=rd.randint(1000,10000)) for _ in range(5001)]
#print(len(warehouses))
#
#sortedWarehouses=dd(list)
#for warehouse in warehouses:
#    sortedWarehouses[warehouse.id].append(warehouse)
#print(len(sortedWarehouses))
#
#totals={}
#for key, warehouse in sortedWarehouses.items():
#    totalQuantity=0
#    print(f"Warehouse: {key}")
#    for info in warehouse:
#        totalQuantity+=info.quantity
#    print(f"Quantity: {totalQuantity}")
#    totals[key]=totalQuantity
#
#print(totals)
#print(sorted(totals.items(),  key=lambda p:p[1], reverse=True))
#----------------------------------------------------

#----------------------------------------------------
"""
Using the match function, find and print all records beginning with 'ORD: ', 
followed by two uppercase letters, an underscore, and exactly five digits. 
If no matching records are found, print an appropriate message. 
Example: ORD: KT_20481
"""

#import re
#found = False
#with open("re_data.in", "r") as file:
#    for line in file:
#        if(re.match(r"ORD: [A-Z]{2}_\d{5}$", line):
#            print(line)
#            found=True
#if not found:
#    print("Not found.\n")

#----------------------------------------------------

#----------------------------------------------------
"""
Using the match function, find and print all records beginning with 'TEL: ', 
followed by +995, a space, and exactly nine digits. 
Print how many records matched and how many did not. 
If no matching records are found, print an appropriate message. 
Example: TEL: +995 598123456
"""

#import re
#found = False
#unmatched =0 
#matched =0 
#with open("re_data.in", "r") as file:
#    for line in file:
#        if(re.match(r"TEL: \+995 \d{9}$", line):
#            print(line)
#            found=True
#            matched+=1
#        else:
#            unmatched+=1
#if not found:
#    print("Not found.\n")
#print(f"Matched: {matched}, Unmatched: {unmatched}")
#----------------------------------------------------

#----------------------------------------------------
"""
Using the match function, find and print all records beginning with 'EMP: ', 
followed by one uppercase letter, a hyphen, exactly three digits, a hyphen, 
and two lowercase letters. If no matching records are found, print an 
appropriate message. Example: EMP: Q-482-xz
"""

#import re
#found = False
#with open("re_data.in", "r") as file:
#    for line in file:
#        if(re.match(r"EMP: [A-Z]-\d{3}-[a-z][a-z]$")):
#            print(line)
#            found=True
#if not found:
#    print("Not found.\n")
#----------------------------------------------------

#----------------------------------------------------
"""
A library catalogs its books by genre. Use namedtuple to define
a tuple-based record type named Book with the attributes id, genre, pages. 
The id attribute identifies the book using a unique code with four digits,
    such as Bk_0042. 
The genre attribute identifies the genre code; there are 12 possible values, 
for example {gn_01, gn_02, ...}. The pages attribute is an integer in [40, 1200]. 
(1) Use appropriate functions from the random module to generate a list containing 
    2,500 records. 
    Example: [Book(id='Bk_0001', genre='gn_07', pages=312), ...]. 
(2) Use defaultdict to group the records by the genre attribute. 
    Calculate the average and total number of pages for each genre. 
(3) Find the genre with the fewest books.
    Print the group and the corresponding result. 
    If several groups are tied, print all of them.
"""
from collections import namedtuple as nt, defaultdict as dd
import random as rd

Book = nt("Book", ["id","genre","pages"])
Books = [Book(id=f"Bk_{_:04d}", genre=f"gn_{rd.randint(1,12):02d}", pages=rd.randint(40,1200)) for _ in range(2500)]
print(len(Books))

sortedBooks=dd(list)
for book in Books:
    sortedBooks[book.genre].append(book)
print(len(sortedBooks))

for key, genre in sortedBooks.items():
    totalPages=0
    for info in genre:
        totalPages+=info.pages
    print(f"ID: {key}")
    print(f"Total Pages: {totalPages}")
    print(f"Average Pages: {totalPages/len(genre)}")

fewest = min([key, len(val)] for key,val in sortedBooks.items())
same = [key for key,book in sortedBooks.items() if len(book)==fewest]
print(f"Fewsest {fewest},with matching: {same}")
#----------------------------------------------------
