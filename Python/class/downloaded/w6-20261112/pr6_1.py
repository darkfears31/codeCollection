class test:
    pass

t = test()

print(id(t))
print(t)

if isinstance(t, test):
    print("instance type - test")
else:
    print("has a type other than test")

lst = list()
if isinstance(lst, test):
    print("instance type - test")
else:
    print("has a type other than test")