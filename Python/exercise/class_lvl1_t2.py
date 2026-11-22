class BankAccount:
    def __init__(self, balance):
        self.__balance=balance
    def deposit(self, amount):
        print(f"Deposited: {amount}")
        self.__balance+=amount
    def withdraw(self, amount):
        if(amount > self.__balance):
            raise ValueError("Withdrawing more then available is big nono.")
        print(f'withdrawing {amount}')
        self.__balance-=amount
    def __str__(self):
        return f"Balance: {self.__balance}" # operator<< overload

b = BankAccount(300)
print(b)
b.deposit(200)
print(b)
b.withdraw(300)
print(b)
try:
    b.withdraw(500)
except:
   print("Withdrawing more then available is big nono.")
print(b)

