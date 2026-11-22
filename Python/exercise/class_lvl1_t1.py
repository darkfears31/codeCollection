class Rectangle:
    def __init__(self, width, height):
        # double undersoce makes variable 'private'
        self.__width=width
        self.__height=height
    def area(self):
        return self.__width*self.__height
    def perimeter(self):
        return 2*(self.__width+self.__height)

r1 = Rectangle(20,40)
print(f"Area: {r1.area()}")
print(f"Perimeter: {r1.perimeter()}")

try:
    print(f"Width: {r1.__width}")
except:
    print("Tried to access private variable.")
