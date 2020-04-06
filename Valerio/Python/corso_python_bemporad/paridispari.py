def paridispari():
    inp = input("Inserisci un numero: ")
    numero = int(inp)
    modulo = numero % 2
    if modulo:
        print("Numero dispari")
    else:
        print("Numero pari")


paridispari()