# Lancia hydrogen in Atom altrimenti questo file non serve a un cazzo :)
# per lanciare hydrogen su una riga, su mac, cmd-enter

import pandas as pd
iris = pd.read_csv("data/iris.csv")
# Le funzioni head(n=5) e tail(n=%) permettono di vedere n righe dall'inizio
# o dalla fine di un dataset
#
# se non avessimo avuto a disposizione la testata della tabella avremmo potuto
# personalizzarla eseguendo
# iris = pd.read_csv("data/iris.csv", header=None, names=["sepal_length", "sepal_width",...ecc])

iris.head()
iris.tail()


# Per accedere alle chiavi delle colonne possiamo utilizzare l'attributo colums
# che vengono restituite all'interno di un iteratore
iris.columns

# Per ottenere invece informazioni sul dataset in generale possiamo utilizzare il metodo info()
iris.info()

# Possiamo accedere ai dati di una colonna utilizzando la sua chiave.
# Il risultato è una series, ovvero un array monodimensionale
Y = iris['species']
Y.head()

type(Y) # come volevasi dimostrare:

# Possiamo anche stampare tabelle personalizzate richiamando il pandas con un array
X = iris[["sepal_length", "sepal_width"]]
X.head()

# È possibile rimuovere righe o colonne tramite il metodo drop() indicando come
# kwarg l'axis, dove questo parametro assume il valore 1 se vogliamo eliminare
# una colonna, e assume il valore 0 quando vogliamo eliminare una riga

# Qui ho eliminato la colonna petal_length
iris.drop("petal_length", axis=1).head()

# Qui ho eliminato la quarta riga
iris.drop(3, axis=0).head()

# Per fare lo slicing dei dati possiamo utilizzare due possibilità: loc e hai iloc
# Creiamo una copia del dataset e mescoliamola con il metodo sample()
# Poiché il tizio che ha fatto questo tutorial parla male, dobbiamo
# utilizzare il frac=1 ma non sappiamo perché

iris_copy = iris.copy().sample(frac=1)
iris_copy.head()

# Ora, la differenza principale tra loc e iloc è che iloc utilizza le label
# mentre loc utilizza gli indici

iris_copy.iloc[3]

iris_copy.loc[72] # se non dovesse essere uguale alla riga sopra sappi che l'indice dovrebbe essere iris_copy.iloc[3].name

# Possiamo cercare in stile battaglia navale una cella in una riga e una colonna loc
# selezionando la riga e la colonna
iris_copy.loc[72, 'species']


#Oppure con iloc possiamo selezionare, ad esempio, le prime 4 righe,
# e per indicare la colonna dobbiamo usare un indice numerico
iris_copy.iloc[:4, 2]

# Con shape possiamo tenere la dimensione del dataset
iris.shape

# Con il metodo describe(), per ogni colonna, Possiamo ottenere informazioni come
# il numero di elementi presenti, la media, la deviazione standard, il minimo,
# la distribuzione e il valore massimo
iris.describe()

# Possiamo Anche essere interessati a un singolo dato statistico, ad esempio
# richiedere il minimo con il metodo min()

iris.min()

# Oppure la varianza su una colonna
iris["sepal_length"].var()

# Se invece vogliamo visualizzare quali sono le variabili di una colonna possiamo utilizzare il metodo unique()

iris["species"].unique()

# È possibile creare una maschera, ovvero un array che mostra tutti gli elementi
# del dataset il cui valore petal_length è maggiore del valore medio di petal_length
iris_petal_mask = iris["petal_length"] > iris["petal_length"].mean()
iris_petal_mask

# È possibile filtrare il dataset con la maschera utilizzandola come un indice
filtered_iris_by_mask = iris[iris_petal_mask]
filtered_iris_by_mask.head()

# Possiamo utilizzare le maschere per modificare alcune caratteristiche del dataset,
# facciamone una copia e trasformiamo tutte le specie setosa in undefined

iris_copy = iris.copy()
iris_copy[iris_copy["species"] == "setosa"] = "undefined"

iris_copy["species"].unique()

# Proviamo ora una normalizzazione, trasformando ciascun elemento della tabella
# nel rapporto fra la differenza del suo valore è il valore minimo e
# la differenza tra il valore massimo il valore minimo

X = iris.drop("species", axis=1)
X_norm = (X - X.min()) / (X.max() - X.min())
X_norm


# Un Altro metodo molto utile è sort_values, che permette di ordinare il dataset in base ai valori di una colonna

iris.sort_values("petal_length")


# Con groupby possiamo raggruppare le selezioni per attributi,
# ad esempio raggruppando per specie visualizzando il valor medio

groupedby_species = iris.groupby("species").mean()
groupedby_species

# Un'altra cosa che può capitare è dover applicare funzioni su righe o su colonne,
# per fare questo utilizziamo il metodo apply()
# In questo caso vogliamo ottenere una series che contiene tutti i valori non nulli
# per riga e per colonna

import numpy as np

# qui otteniamo il numero di colonne per riga che contengono elementi non nulli
iris.apply(np.count_nonzero, axis=1)

# qui otteniamo il numero di righe per colonna che contengono elementi non nulli
iris.apply(np.count_nonzero, axis=0)

# Possiamo anche voler applicare una funzione all'intero dataset, e per questo
# utilizzeremmo applymap.
# Supponiamo, ad esempio, di voler arrotondare tutti i valori delle colonne numeriche

iris.drop("species", axis=1).applymap(lambda x : int(round(x)))

# A volte, in un'osservazione statistica, può succedere di avere dei valori nulli
# Non avendo noi dei valori nulli all'interno di iris li inseriamo
# creando un array di 10 elementi casuali compresi tra 0 e 150 che rappresentano
# indici di iris, quindi con loc andiamo a selezionare ciascuno di questi
# 10 elementi trasformando la loro proprietà petal_length in None

iris_nan = iris.copy()
samples = np.random.randint(iris.shape[0], size=(10))
samples
iris_nan.loc[samples, "petal_length"] = None

# Possiamo contare il numero di elementi nulli usando la funzione isnull(),
# che crea una siries che contiene false per tutti valori non nulli e true per i valori nulli,
# quindi con la funzione sum possiamo sommare gli elementi true ovvero contarli
iris_nan["petal_length"].isnull().sum()

# Possiamo sostituire i valori nulli con il valor medio.
# Con inplace ci assicuriamo che iris_nan venga modificato come se
# fosse stato un riferimento
mean_petal_length = iris_nan["petal_length"].mean()
iris_nan["petal_length"].fillna(mean_petal_length, inplace=True)

# Infine Panda s'Center faccio molto bene anche con la libreria matplotlib,
# che serve a costruire grafici.
# In questo caso creeremo un grafico a dispersione

import matplotlib.pyplot as plt

iris.plot(x='sepal_length', y='sepal_width', kind='scatter')
