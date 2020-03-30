# Una tupla è una sequenza di elementi immutabili, ovvero una volta inseriti non possono essere
# modificati

# type = <class 'tuple'>

# ecco come dichiarare una tupla

medaglie = ()
medaglie = tuple()

medaglie = ("Oro", "Argento", "Bronzo")
medaglie = "Oro", "Argento", "Bronzo"

print(medaglie)

# con le tuple si può fare l'unpacking (tipo destructuring in js ma gli elementi vanno estratti tutti)

o, a, b = medaglie
print(o)
print(a)
print(b)

x, y = medaglie
print(x)
print(y)