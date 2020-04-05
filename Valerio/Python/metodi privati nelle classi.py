# Cominciamo col tenere presente che come qualsiasi linguaggio debolmente tipato
# python è una fighetta, per tanto le cose sofisticate non gli piacciono.
# In python non esiste un metodo infallibile per definire in maniera
# efficace una proprietà o un metodo realmente privato in una classe, tuttavia
# python mette a disposizione una tecnica che si chiama "Name Mangling", ovvero
# storpiamento del nome, che rende un attributo o un metodo talmente irraggiungibile
# da sembrare apparentemente privato. La tecnica consiste nel dichiarare un metodo
# o un attributo facendolo precedere da due underscoor, tipo __myMethod().
# Facendo questa cosa l'unico modo per accedere direttamente a tale metodo o attributo,
# supposto che l'attrributo appartenga alla classe MyClass e l'istanza della classe
# sia m1, la sintassi sarebbe m1._MyClass__myMethod() oppure m1._MyClass__myAttr ... .
# Va da se che data l'evidente sbattosità inerente al richiamo di tali proprietà, conviene
# rivolgersi a questi metodi tramite getters e setters, definiti nella canonica maniera
# di java. Va tuttavia ricordato che per usare tali getters e setters conviene usare una sorta di
# aliasing consistente nella built-in function "property(prop1,...,propN)" che permette di utilizzare
# il nostro metodo privato con un nuovo nome ricevendo come parametri i nostri getter and setters.

class MyClass:
    def __init__(self, attr):
        self.__mySecretAttr = attr

    def getAttr(self):
        return self.__mySecretAttr

    attr = property(getAttr)

m1 = MyClass('Mario')

print(f"m1.attr = '{m1.attr}'") # mario

nome = "Giulia"

try:
    m1.attr = nome
except:
    print(f"\x1b[91mErrore: La proprietà 'attr' non può essere modificata in '{nome}' perche 'attr' è una proprietà privata in '{m1} \x1b[0m")

m1._MyClass__mySecretAttr = nome
if m1.attr == nome:
    print(f"ok tutto bene, m1.attr = '{m1.attr}'")
else:
    print(f"\x1b[91mAh boh... per quanto ne so doveva andare tutto bene 🤷🏾\x1b[0m")
