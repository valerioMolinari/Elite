# in una funzione è possibile aggiungere annotazioni riguardanti parametri e valori di ritorno
# senza che questo produca alcun effetto reale sulla funzione

def myfunc(x: "parametro x") -> "ritorno x":
    return x

print(myfunc(10))

# tuttavia è possibile mostrare le annotazioni inserite tramite la proprietà delle funzioni __annotations__
# come un dizionario

print(myfunc.__annotations__)
print()

# Esistono poi i type annotation, ovvero specicazioni sul tipo

def myFunc(x: int, y: str = "python") -> str :
    print(x)
    return y

print(myFunc(40))
print(myFunc.__annotations__)
print()

# tutto questo può anche fatto su una variabile e __annotations__ viene richiamato al livello globale

a: int = 15
print(a)
print(__annotations__) # è pycharm che lo sottolinea di rosso ma è consentito
print()

# l'annotazione di tipo può essere usata anche nelle classi

class MyClass:
    nome: str
    cognome: str

    def __init__(self, nome, cognome):
        self.nome = nome
        self.cognome = cognome

mc = MyClass("Valerio", "Molinari")
print(mc)
print(mc.nome)
print(mc.cognome)
print(MyClass.__annotations__)

