import numpy as np

def linear(a,b=0):
    return [x for x in (range(a, b) if b else range(a))]

a = np.array([linear(1,8), linear(8,15)])
a

# vediamo che si tratta di una matrice 2x7
a.shape

# se vogliamo accedere ad uno specifico elemento usiamo la notazione a[row, col]
a[1,3] # seconda riga, quarta colonna

# otteniamo una riga specifica utiliziamo la notazione a slice selezionando
# come riga una riga e come colonna tutto dall'inizio alla fine, ovvero utilizzando
# semplicemente i :
a[0,:]

# otteniamo una specifica colonna tramite lo stesso processo
a[:,4]
