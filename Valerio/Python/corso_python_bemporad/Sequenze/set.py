# Un set è un insieme mutabile

# type = <class 'set'>

# può essere costruito con costruttore a partire da una lista oppure in formato literal tramite {}

mySet = set()
mySet = set([10, 20, 30, 40])

mySet = {10, 20, 30, 40}
# mySet = {} -> non si può creare un set vuoto col formato literal, questo è un dizionario



# frozenset è un insieme immutabile

# type = <class 'frozenset'>

myFrozenSet = frozenset([10, 20, 30])

# myFrozenSet.add(40) "solleva un'eccezione"



# Tra insiemi è possibile eseguire operazioni di insiemistica elementare

A = {10, 20, 30, 40}
B = {30, 40, 50, 60}

INTERSEZIONE = A & B # {40, 30}
UNIONE = A | B # {40, 10, 50, 20, 60, 30}
DIFFERENZA1 = A - B # {10, 20}
DIFFERENZA2 = B - A # {50, 60}
XOR = A ^ B # {10, 50, 20, 60}

# per il cartesiano bisogna importare la libreria itertools e accedere a product
# documentazione https://docs.python.org/3/library/itertools.html#itertools.product