import numpy as np

_a = [i for i in range(30)]
_b = [[j for j in range(i, i + 10)] for i in range(0,100,10)]

a = np.array(_a)
b = np.array(_b)

a
b

# boolean indexing
a[a > 14]

a[(a%8 == 0)] * 100

# multimatrix indexing

# tutto l'array
b
b[:]
b[:,:]
b[::,::]

# slice sulle righe

b[4:]

b[5:7]

b[:4:2]

# slice sulle colonne

b[:,2:]

b[:,5:7]

b[:,:9:3]

# slicing misto

# dalla prima alla quinta riga, dalla seconda all'ottava colonna saltandone 2 alla volta
b[:5, 1:8:2]
