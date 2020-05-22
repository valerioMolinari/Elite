from random import randint
from Reader import Reader

class Cypher:
    def __init__(self, **kwargs):
        if 'string' in kwargs:
            self.__text = kwargs['string'].lower()
        elif 'file' in kwargs:
            file = kwargs['file']
            self.__text = Reader.read(file).lower()
        else:
            raise Exception("Missing source text")

        alpha = []
        if 'alpha' in kwargs:
            alpha = kwargs['alpha']
        else:
            alpha = [chr(l) for l in range(97, 123)]

            for i in range(26):
                random = randint(0, 25)
                hold = alpha[i]
                alpha[i] = alpha[random]
                alpha[random] = hold

        self.__alpha = {chr(l):alpha[i] for l,i in zip(range(97, 123), range(26))}

    def __crypt(self, text, dictionary: dict) -> str:
        text = list(text)
        for i in range(len(text)):
            text[i] = dictionary[text[i]] if text[i] in dictionary else text[i]
        return ''.join(text)

    def crypt(self) -> str:
        return self.__crypt(self.__text, self.__alpha)

    def decrypt(self, text, **kwargs) -> str:
        dictionary = {}
        if 'stringDict' in kwargs:
            dictionary = {c: chr(l) for l,c in zip(range(97,123), kwargs['stringDict'])}
        else:
            dictionary = kwargs['dict']
        if len(dictionary) != 26:
            raise Exception("Dictionary must have 26 letters")
        return self.__crypt(text, dictionary)

    @property
    def alpha(self):
        return self.__alpha

    @property
    def text(self):
        return self.__text
