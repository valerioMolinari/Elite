# type = str
# supporta il set UNICODE
# le stringhe sono immutabili (tipo vengono salvate nell'heap e puntate nel solito modo)
# si assegnano con apici singoli o doppi apici
# si può usare il triplo apice o triplo doppio apice per scrivere una stringa su più linee

s = """Si può creare una stringa 
multiline scrivendo il triplo apice
o il triplo doppio apice
"""

print(s)

# sequenze di escape
t = "scrivo qualcosa\ne poi vado a capo\n"

print(t)

u = "metto un\tgrande spazio\n"

print(u)

print("Per stampare la barra \\ ne devo mettere 2\n")

print("Ho scritto una stringa usando il carattere \" all'inizio e alla fine\n")

# string interpolation

titolo = "isola misteriosa"
autore = "Jule Verne"
print(f"Titolo: {titolo}, autore: {autore}")
