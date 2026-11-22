class Rectangle:
    def __init__(self, width, height):
        # double undersoce makes variable 'private'
        self.__width=width
        self.__height=height
    def area(self):
        return self.__width*self.__height
    def perimeter(self):
        return 2*(self.__width+self.__height)
    def __str__(self):
        return f"Width: {self.__width}, Height: {self.__height}"
    def __repr__(self):
        return f"Rectangle(width={self.__width}, height={self.__height})"

r1 = Rectangle(20,40)
print(f"Area: {r1.area()}")
print(f"Perimeter: {r1.perimeter()}")
print(r1)
print(repr(r1))

