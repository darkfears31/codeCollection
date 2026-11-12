class Test:
    def __init__(self, nm):
        self.name=nm
    def func1(self):
        print(f"Hello {self.name}")
    def func2(obj):
        print(f"Hello 2 {obj.name}")

t1 = Test('Name1')
t1.func1()
t1.func2()

class Point:
    def __init__(self, x,y,z):
        self.att1=x
        self.att2=y
        self.addThirdCord(z)
    def mulitply(self,val):
        self.att1*=val
        self.att2*=val
        return self
    def addThirdCord(self, z):
        self.att3=z
    def __repr__(self):
        return f'att1: {self.att1}, att2: {self.att2}, att3: {self.att3}'

#p1 doesnt have att3, because it isn't defined in constructor.
p1 = Point(10,20,30)
try:
    print(p1);
except:
    print("att3 isnt there.\n")
p1.mulitply(5)

class pt:
    def __init__(self, x):
        self.__att1=x
    @staticmethod
    def st_method(arg):
        print(f'hello from static method {arg}\n')
    @property
    def attr(self):
        return self.__att1
    @attr.setter
    def attr(self, val):
        self.__att1=val
    def __repr__(self):
        return f'att1: {self.__att1}'

p1=pt(5)
print(p1)
p1.attr=50
print(p1)
pt.st_method("aba ra")
