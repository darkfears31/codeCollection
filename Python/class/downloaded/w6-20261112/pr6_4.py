class test:
    st = "Static attribute"
    def __init__(self):
        self.attr = "Instance-level attribute"

    def __str__(self):
        return f'attr1 = {self.attr}'

    def __repr__(self):
        return str(self)

t1 = test()
print(t1)
print(f't1.st   = {t1.st}')
print(f'test.st = {test.st}')

# Creating a new attribute for an instance
t2 = test()
print(f't2.st = {t2.st}')
try:
    print(f't2.new_atttr = {t2.new_cl_attr}')
except:
    print(f't2 does not have the attribute new_cl_attr')
test.new_cl_attr = 'New class attribute'
print(f'test.new_cl_attr = {test.new_cl_attr}')
print(f'An attribute named `new_cl_attr` appeared on `t2`: {t2.new_cl_attr}')





