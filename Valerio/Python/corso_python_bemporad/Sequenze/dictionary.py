# è tipo l'oggetto in js i cui elementi sono mutabili
# è un oggetto puntato, per crearne una copia si usa il metodo .copy()

# type = <class 'dict'>

myDict = dict()
myDict = {}

myDict = {
    "primo" : 10,
    "secondo" : 20,
    "terzo" : 30
 }

# l'accesso si fa con le quadre

print(myDict["secondo"])

myDict["quarto"] = 40

print(f"myDict: {myDict}")

del myDict["secondo"]

print(f"myDict: {myDict}")

print("quarto" in myDict)

# metodo .items() dei dizionari permette di ottenere un "iteratore" del dizionario,
# ovvero una lista contenente una serie di tuple di due elementi:
# chiave e valore

d_i = myDict.items() # dict_items([('primo', 10), ('terzo', 30), ('quarto', 40)])

# la notazione a costruttore dict() può convertire un iteratore dict_items in un dizionario
myDict2 = dict(d_i) # {'primo': 10, 'terzo': 30, 'quarto': 40}

# con il metodo update si può aggiungere un dizionario ad un dizionario

newDict = {"quinto" : 50}
myDict2.update(newDict) # {'primo': 10, 'terzo': 30, 'quarto': 40, 'quinto': 50}
print(myDict2)

# per eliminare il dizionario:

myDict.clear()

print(f"myDict: {myDict}")
# oppure

myDict = {}

