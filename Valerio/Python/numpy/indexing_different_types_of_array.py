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
