# Una lista è una sequenza di tipi mutabili, il tipo è type = list

myList = [] # lista vuota
myList = list() # lista vuota con costruttore
myLst = [10, 20, 30] # lista non vuota

myList[1] # 20
myList[-1] # 30

myList.insert(2, 50) # [10, 20, 50, 30]
myList.append(60) # [10, 20, 50, 30, 60]
del myList[1] # [10, 50, 30, 60]
30 in myList # True
20 in myList # False

# Gli identificatori delle liste sono puntatori

# Con il metodo delle liste copy() possiamo evitare il problema del riferimento, tant'è che
myList2 = myList.copy() # puntano a due liste diverse