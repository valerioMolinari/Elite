# questo senza decoratore

def myFunc():
    print("La funzione myFunc\n")

def myDecorator(f):
    def decorator():
        print("Ho decorato")
        f()
    return decorator

myFunc = myDecorator(myFunc)

myFunc()

# con decoratore

@myDecorator
def anotherFunc():
    print("Un'altra funzione")

anotherFunc()
