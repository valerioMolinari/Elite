import numpy as np

# indicizzare una matrice di zeri
a = np.zeros(5)
a

b = np.zeros((2,3,4), dtype='int16')
b

# per matrici di tutti 1 si utilizza np.ones(dim, *args, **kwargs)
c = np.ones((2,4))
c
# mentre per qualsiasi altro numero si usa full
d = np.full((3,2,2), 23, dtype='int16')

# possiamo anche utilizzare una dimensione già creata e utilizzare full_like

e = np.full_like(b, 3)

# possiamo generare una matrice di valori casuali fra 0 e 1 tramite random.rand
# passando la shape come parametro

np.random.rand(4,2)
np.random.rand(*e.shape)

# per creare una matrice di interi usiamo randint
np.random.randint(10, size=(2,2))
