"""
Cos'è numpy?
    numpy è una libreria per array multidimensionali
Perché usare numpy piuttosto che le liste?
    le liste sono molto lente mentre numpy è molto veloce.
    numpy è più veloce perché è tipato, infatti possiamo specificare
    la rappresentazione binaria dei numeri come int32 per un int,
    int16 per uno short, int8 per un char...
    In altre parole numpy utilizza molta meno memoria.
    Un'altra ragione è che le liste registrano gli elementi randomicamente nella
    memoria, nunpy li registra contiguamente.
    Infine numpy permette di fare molte più cose rispetto alle liste:
        es:
            a = [1,2,3]
            b = [4,5,6]
            a*b #error

            a = np.array([1,2,3])
            b = np.array([4,5,6])
            a*b = np.array([4,10,18])
Applicazioni di numpy:
    matematiche (matlab)
    plotting (matplotlib)
    backend (pandas, connect 4, digital photography)
    machine learning
"""

import  numpy as np

a = np.array([1,2,3], dtype="int16")
print(a)
b = np.array([[9.,8.,7.,],[6.,5.,4.,]])
print(b)

# Possiamo ottenere la dimensione tramite ndim
a.ndim #array monodimensionale
b.ndim #array bidimensionale

# Possiamo ottenere la forma di un array tramite shape
a.shape
b.shape

# Possiamo ottenere il tipo di dati tramite dtype
a.dtype
b.dtype

# Possiamo ottenere la quantità di byte occupata dai singoli elementi tramite itemsize
a.itemsize
b.itemsize

# Possiamo ottenere la dimensione totale tramite nbytes
a.nbytes
b.nbytes

# Possiamo ottenere la quantità totale di un array tramite size che restituisce
# una produttoria degli elementi di shape
a.size
b.size
