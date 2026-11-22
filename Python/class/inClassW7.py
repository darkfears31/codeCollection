#class Test:
#    def __init__(self, a, b):
#        self.attr=a
#        self.attr2=b
#
#    def add_attr(self,a):
#        self.attr2=a 
#
#t1=Test(10, 30)
#print(t1.attr)
#
#try:
#    print(t1.attr2)
#except:
#    print("doesnt have such attribute.\n")
#
#t1.attr3=90
#try:
#    print(t1.attr3)
#except:
#    print("doesnt have such attribute.\n")

#class Test:
#    cl_lev_attr="class attribute"
#    def __init__(self, a, b):
#        self.attr1=a
#
#t1 = Test(1,2)
#print(t1.cl_lev_attr)
#print(Test.cl_lev_attr)
#
#t1.cl_lev_attr="instance attribute"
#print(t1.cl_lev_attr)
#print(Test.cl_lev_attr)
#
#Test.cl_lev_attr="rame"
#t2 = Test(3,4)
#print(t1.cl_lev_attr)
#print(t2.cl_lev_attr)
#print(Test.cl_lev_attr)


#class Parent:
#    def __init__(self, a, b):
#        self._attr1=a # protected
#        self.__attr2=b # private
#    def __str__(self):
#        a=self._attr1 
#        b=self.__attr2
#        return f"_attr1={a}, __attr2={b}"
#
#class Child(Parent):
#    def __init__(self, a, b, c):
#        super().__init__(a,b)
#        self.attr3=c
#    def __str(self):
#        return f"{super().__str__()}, attr3={self.attr3}"
#
#c = Child(1,2,3)
#print(c.attr3, c._attr1)
#print(c)

#class Test:
#    cl_lev_attr='class attriute'
#    def __init__(self, a):
#        self.__attr1=a
#
#    @property
#    def attr(self):
#        return self.__attr1
#
#    @attr.setter
#    def attr(self, value):
#        self.__attr1=value
#    
#t=Test(10)
#try:
#    print(t.__attr1)
#except:
#    print("error")
#
#print(t.attr)
#t.attr=20
#print(t.attr)

from abc import ABCMeta, abstractmethod

class Parent(metaclass=ABCMeta):
    def __init__(self, a):
        self._attr1=a
    @staticmethod
    def st_method():
        print('static method.')
    def getAtt(self):
        return self._attr1
    def some_method(self):
        pass

class Child(Parent):
    def __init__(self, a):
        super().__init__(a)
    def some_method(self):
        print('some_method() was overriden')

p=Parent(1)
print(p.getAtt())
Parent.st_method()

c=Child(2)
print(c.getAtt())
try:
    c.some_method()
except:
    print("not implemented.")
