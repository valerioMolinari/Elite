from random import randint
from colors import *
from time import sleep
import math

class GuessMe:
    __my_number: int
    bound: int

    def __init__(self, bound : int):
        self.__my_number = randint(0, bound)
        self.bound = bound

    def ai_resolver(self):
        cyan("Ciao sono l'I.A.")
        sleep(1)
        cyan(f"Proverò a indovinare questo numero tra 0 e {self.bound} sperando di metterci al massimo {math.ceil(math.log2(self.bound))} tentativi 😊")
        sleep(3)
        attempt = half = self.bound // 2
        count = 1
        while True:
            cyan(f"{count}° tentativo: {attempt}?")
            if attempt != self.__my_number:
                half = math.ceil(half / 2)
            else:
                break

            sleep(.3)
            if self.__my_number > attempt:
                red("Il numero è più grande")
                attempt += half
            else:
                red("Il numero è più piccolo")
                attempt -= half
            sleep(.5)
            cyan("Elaboro...\n")
            count += 1
            sleep(1)

        green(f"L'I.A. ha indovinato il numero {self.__my_number} in {count} tentativi!")

    def human_resolver(self):
        green(f"Prova a indovinare un numero tra 0 e {self.bound}, ma cerca di non metterci più di {math.ceil(math.log2(self.bound))} tentativi 😉")
        attempt = 0
        count = 1
        while True:
            try:
                attempt = int(input(f"{count}° tentativo: "))
                if self.__my_number > attempt:
                    red("Il numero è più grande")
                elif self.__my_number < attempt:
                    red("Il numero è più piccolo")
                else:
                    if count <= math.ceil(math.log2(self.bound)):
                        green(f"Bravo! Hai indovinato il numero {self.__my_number} in solo {count} tentativi")
                    else:
                        green(f"Ok hai indovinato il numero {self.__my_number} in {count} tentativi ma potevi fare di meglio...")
                    break
                count += 1
            except:
                red("Qualcosa è andato storto, probabilmente non hai inserito un numero, riprova")

GuessMe(1_000_000_000_000_000_000).ai_resolver()
#GuessMe(100).human_resolver()
