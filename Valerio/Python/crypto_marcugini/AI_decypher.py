import Cypher
from Alpha import Alpha
from Reader import Reader

class AI_decypher:
    def __init__(self, **kwargs):
        lang_dict_path = kwargs['lang_dict_path']
        if 'file' in kwargs:
            self.__text = Reader.read(kwargs['file'])
        elif 'string' in kwargs:
            self.__text = kwargs['string'].lower()
        terms_list = list(map(lambda s: s[:-1], Reader.readlines(lang_dict_path)))
        lengths = set(map(lambda s: len(s), terms_list))
        min_length = min(lengths)
        max_length = max(lengths)
        term_matrix = {}
        for i in range(min_length, max_length + 1):
            term_matrix[i] = []
            for term in terms_list:
                if len(term) == i:
                    term_matrix[i].append(term)
        self.__term_matrix = term_matrix

        self.__dict_entropy = AI_decypher.__get_entropy(terms_list)
        self.__entropy = AI_decypher.__get_entropy(self.__text)
        if 'entropy_from' in kwargs:
            self.__entropy_from_documents = None
            for file in kwargs['entropy_from']:
                self.__entropy_update(AI_decypher.__get_entropy(Reader.read(file), raw=True))

    @staticmethod
    def __get_entropy(source: str or list, raw: bool = False) -> Alpha:
        entropy = {chr(l): 0 for l in range(97, 123)}
        for letter in entropy:
            if isinstance(source, list):
                for term in source:
                    entropy[letter] += term.count(letter)
            else:
                entropy[letter] += source.count(letter)
        if raw:
            return Alpha(entropy)
        return AI_decypher.__normalize(entropy)

    def __entropy_update(self, entropy_dict: Alpha) -> None:
        if self.__entropy_from_documents == None:
            self.__entropy_from_documents = {chr(l): 0 for l in range(97, 123)}
        for letter in self.__entropy_from_documents:
            self.__entropy_from_documents[letter] += entropy_dict.dictionary[letter]

    @staticmethod
    def __normalize(entropy: dict) -> Alpha:
        entropy_values = entropy.values()
        e_min = min(entropy_values)
        e_max = max(entropy_values)
        return Alpha({letter: round((value - e_min) / (e_max - e_min), 3) for letter, value in zip(entropy, entropy_values)})

    def decrypt(self):
        pass

    @property
    def term_matrix(self):
        return self.__term_matrix

    @property
    def dict_entropy(self):
        return self.__dict_entropy

    @property
    def entropy(self):
        return self.__entropy

    @property
    def entropy_from_documents(self):
        return AI_decypher.__normalize(self.__entropy_from_documents)
