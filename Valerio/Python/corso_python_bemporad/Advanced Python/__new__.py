# In realtà in python la funzione __init__ non sarebbe un vero e proprio costruttore, piuttosto
# si tratta di un inizializzatore, il vero costruttore, che però opera dietro le quinte,
# è il metodo di classe __new__ definito all'interno della classe type (o object non ricordo)
# che viene ereditato da qualsiasi classe venga creata.
# Viene richiamato in fase di istanziazione dell'oggetto e prende come parametro la classe stessa
# creando un'istanza dell'oggetto richiamando __new__ della superclasse passandogli la classe
# da istanziare, quindi ritorna tale istanza.
# Il metodo __init__ prende come parametro "self", ovvero l'istanza restituita da __new__,
# quindi inizializza l'oggetto
# Qualsiasi parametro si voglia passare a __init__ va prima passato a __new__ che
# lo rimbalzerà direttamente a __init__.
#
# Tieni presente che questa è più che altro una curiosità visto che tutto questo avviene,
# di fatto, dietro le quinte, quindi è difficile che occorra fare un override del metodo __new__

class MyClass:
    def __new__(cls):
        istanza = super().__new__(cls)
        print("Oggetto MyClass creato")
        return istanza

    def __init__(self):
        print("Oggetto MyClass inizializzato\n")

class MyClass2:
    def __new__(cls, message):
        istanza = super().__new__(cls)
        print("Oggetto MyClass2 creato")
        return istanza

    def __init__(self, message):
        print("Oggetto MyClass inizializzato")
        print(f"Message: {message}")

obj = MyClass()
obj2 = MyClass2("Python")