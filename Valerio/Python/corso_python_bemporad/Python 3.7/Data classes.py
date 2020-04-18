from dataclasses import dataclass

# una data class è una classe che serve a definire degli attributi piuttosto che dei comportamenti
# il decoratore dataclass, una volta aggiunte le annotazioni di tipo agli attributi, entra in azione
# creando alcuni metodi dietro le quinte

@dataclass
class MyDataClass:
    nome: str
    cognome: str

    # def __init__(self, nome: str, cognome: str) -> None:
    #   self.nome = nome
    #   self.cognome = cognome

    # def __repr__ -> serve a stampare una versione "più amichevole" della classe
    # def __eq__ -> restituisce se due istanze sono uguali confrontando attributo per attrubuto
    # def __ne__ -> not __eq__

vm = MyDataClass("Valerio", "Molinari")
print(vm) # MyDataClass(nome='Valerio', cognome='Molinari') -> grazie a __repr__
gp = MyDataClass("Giulia", "Pastorelli")
print(gp)
print()
print(vm.__eq__(gp))
print(gp.__ne__(vm))


# il decoratore @dataclass ha un comportamento di default del tipo
# @dataclass(init=True, repr=True, order=False, frozen=False)
# in fase di creazione questo comportamento può essere alterato in base alle necessita