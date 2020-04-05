natural = lambda : print('\x1b[0m', end = '')
green = lambda : print('\x1b[32m', end = '')
red = lambda : print('\x1b[31m', end = '')
cyan = lambda : print('\x1b[36m', end = '')
yellow = lambda : print('\x1b[33m', end = '')

class Conto:
    def __init__(self, nome, conto):
        self.__nome = nome
        self.__conto = conto

    @property
    def nome(self):
        return self.__nome

    @property
    def conto(self):
        return self.__conto

class ContoCorrente(Conto):
    def __init__(self, nome, conto, importo=50.):
        super().__init__(nome, conto)
        self.__saldo = importo
        green()
        print("Nuovo conto corrente: ")
        self.descrizione()
        natural()

    def preleva(self, importo):
        red()
        if self.__saldo >= importo:
            self.__saldo -= importo
            print(f"Prelievo di %.2f€ dal cc {self.conto}\n" % importo)
        else:
            print(f"Prelievo di %.2f€ dal cc {self.conto}, il conto è vuoto\n" % importo - self.__saldo)
            self.__saldo = 0
        natural()

    def deposita(self, importo):
        self.__saldo += importo
        cyan()
        print(f"Deposito di %.2f€ sul cc {self.conto}\n" % importo)
        natural()

    def descrizione(self):
        print(f"nome  : {self.nome}\nconto : {self.conto}\nsaldo : %.2f€\n" % self.__saldo)

class GestoreContiCorrenti:
    @staticmethod
    def bonifico(sorgente, destinazione, importo):
        sorgente.preleva(importo)
        destinazione.deposita(importo)
        yellow()
        print(f"Bonifico di %.2f€ eseguito dal cc {sorgente.conto} al cc {destinazione.conto}\n" % importo)
        natural()

c1 = ContoCorrente("Mario Rossi", 5392, 100.)
c1.deposita(1500)
c1.preleva(200)
c1.descrizione()
c2 = ContoCorrente("Giulia Pastorelli", 6342, 200.)
c2.deposita(1600)
c1.preleva(100)
c2.preleva(300)
c1.deposita(1500)
c2.preleva(50)
GestoreContiCorrenti.bonifico(c1, c2, 300)
c1.descrizione()
c2.descrizione()
