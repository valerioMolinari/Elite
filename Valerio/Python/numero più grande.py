print("Inserisci 10 numeri e ti dirò qual è il più grande:")
counter = 0
numero = 0
maggiore = 0

while counter < 10:
    numero = input(f"{counter + 1}° numero: ")
    try:
        numero = int(numero)
    except:
        print("\t\x1b[31mErrore: devi inserire un numero, non una stringa\x1b[0m")
        continue
    counter += 1
    maggiore = numero if maggiore < numero else maggiore

print(f"\nIl maggiore dei 10 numeri è \x1b[1m{maggiore}")
