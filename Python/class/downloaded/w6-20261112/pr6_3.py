class test:
    st = "სტატიკური ატრიბუტი"
    def __init__(self):
        self.attr = "ეგზემპლარის დონის ატრიბუტი"

    def __str__(self):
        return f'attr1 = {self.attr}'

    def __repr__(self):
        return str(self)

t1 = test()
print(t1)
print(f'st = {t1.st}')
print(f'st = {test.st}')

# ეგზემპლარისთვის ახალი ატრიბუტის გაკეთება
t2 = test()
t2.new_attr =  "t2 -ის დამატებითი ატრიბუტი"
print(f't2.attr      = {t2.attr}')
print(f't2.new_atttr = {t2.new_attr}')

try:
    print(f't1.new_atttr = {t1.new_attr}')
except:
    print(f't1 -ს არ გააჩნია ატრიბუტი new_atttr')



