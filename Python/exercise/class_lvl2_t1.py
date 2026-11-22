class BankAcc:
    def __init__(self, balance):
        self.__balance=balance
    @property
    def balance(self):
        return self.__balance
    def __str__(self):
        return f"Balance: {self.__balance}"

b=BankAcc(100)
try:
    print(b.__balance)
except:
    print("Naw dawg.")
print(f"Balance (with @property): {b.balance}")
print(b)

