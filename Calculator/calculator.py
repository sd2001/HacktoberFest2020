# Simple Calculator
def add(a, b):
    return a + b
def sub(a, b):
    return a - b
def mult(a, b):
    return a * b
def div(a, b):
    return (a / b)
def mod(a, b):
    return a%b
x = int(input("First number: "))
y = int(input("Second number: "))

print("\n1 - add")
print("2 - subtract")
print("3 - multiply")
print("4 - divide")
print("5 - Remainder")

choice = int(input("Choose: "))

if (choice == 1):
    print(add(x,y))
elif (choice == 2):
    print(sub(x,y))
elif (choice == 3):
    print(mult(x,y))
elif (choice == 4):
    print(div(x,y))
elif (choice==5):
    print(mod(x,y))
else:
    print("Invalid Choice!")
