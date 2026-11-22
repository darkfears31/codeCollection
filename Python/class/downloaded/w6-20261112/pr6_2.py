        self.attr2 = at2

    def __str__(self):
        return f'attr1 = {self.attr1}, attr2 = {self.attr2}'

    def __repr__(self):
        return str(self)

t = test(3, 5)
print(t)


