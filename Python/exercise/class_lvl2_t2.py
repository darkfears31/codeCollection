class Rectangle:
    def __init__(self, width, height):
        self._width=width
        self.height=height
    def area(self):
        return f"Area: {self._width*self.height}"
    def perimeter(self):
        return f"Perimeter: {2*(self._width+self.height)}"
    def __str__(self):
        return f"Height: {self._height}, Width: {self._width}"
    @staticmethod



