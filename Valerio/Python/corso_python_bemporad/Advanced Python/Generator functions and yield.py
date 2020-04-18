def pow_2_till_300():
    i = 2
    while i < 300:
        yield i
        i *= 2
# yield serve a dire alla funzione di rilasciare in "lazy mode" l'elemento 'i', ovvero
# ogni volta che viene richiamato next(), prosegue la sua esecuzione all'iterazione successiva.
# Sostanzialmente è come se la funzione rimanesse in sospeso.
# Poiché la funzione genera un iteratore questo può essere utilizzato una sola volta e poi viene
# "consumato", tuttavia la creazione dell'iteratore, che potrebbe iterare miliardi di elementi,
# viene creato istantaneamente, al contrario di una lista che invece viene inizializzata subito


iterator = pow_2_till_300()

for i in iterator:
    print(i)

# questo ciclo non produce niente poiché iterator è stato consumato
for i in iterator:
    print(i)

generator_expression = (2 ** i for i in range(1, 10) if 2 ** i < 300)

# un iteratore può essere creato anche tramite una generator expression che, sostanznialente,
# equivale ad una list comprehension tranne che per l'uso delle parentesi tonde
print("\nGenerator expression")
for i in generator_expression:
    print(i)