# Un iterabile è un oggetto che ritorna un iteratore, ovvero un oggetto di cui è possibile iterare
# gli elementi. Prendiamo ad esempio una lista:

mylist = ["Mario", "Giulia", "Fringe"]

# La lista è un iterabile e da essa possiamo ottenere l'iteratore tramite la funzione iter:

mylist_iterator = iter(mylist)
print(mylist_iterator) # <list_iterator object at 0x108173cf8>

# come possiamo vedere mylist_iterator si presenta come un oggetto list_iterator, cosa testimoniata
# anche dalla funzione type

print(type(mylist))          # <class 'list'>
print(type(mylist_iterator)) # <class 'list_iterator'>

# gli iteratori possono essere iterati tramite la funzione next, che li scorre elemento per elemento
# finché non arriva alla fine dove, se si prova a iterare ancora, si incorre in un'eccezione

print(next(mylist_iterator)) # Mario
print(next(mylist_iterator)) # Giulia
print(next(mylist_iterator)) # Fringe
try:
    print(next(mylist_iterator))
except StopIteration:
    print("*** Limite di iterazioni raggiunto ***")

# Un iteratore può essere scorto una sola volta e poi diventa inutile, tuttavia la sua praticità
# è data dal fatto che la sua creazione, a prescindere dalla dimensione, è immediata,
# ma questo concetto si comprende meglio grazie alle Generator Functions quindi yield


