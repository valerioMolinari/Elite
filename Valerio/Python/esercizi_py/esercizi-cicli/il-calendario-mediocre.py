#
# Il calendario mediocre
# Scrivi un programma che stampi il calendario di un mese, ricevi in input:
#   - Il numero di giorni nel mese
#   - Il giorno della settimana in cui questo comincia (0: lunedì ... 6: domenica)
#
# Variante
# Piuttosto che passarein input i giorni del mese passa direttamente il mese e calcola tu i giorni corrispondenti.
# http://www.imparareaprogrammare.it
#

m = input("Che mese è? ")
gdm = int(input("Quanti giorni ha? "))
start = int(input("Con che giorno comincia? "))
g = 'lunedì', 'martedì', 'mercoledì', 'giovedì', 'venerdì', 'sabato', 'domenica'

print(f"Calendario di {m}\n")
for i in range(gdm):
    print(f"{i + 1} {g[(start + i) % 7]}")
