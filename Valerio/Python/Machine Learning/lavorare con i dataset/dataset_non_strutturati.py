import re
import math

def phrase_splitter(phrase: str) -> list:
    return list(map(lambda s : re.sub(r'\W','',s.lower()), phrase.split(' ')))

def bag_of_words(phrase: str) -> list:
    split = phrase_splitter(phrase)
    dct = {key: 0 for key in split}
    for key in split:
        dct[key] += 1
    return list(dct.items())

def tf_idf(*args: str, **kwargs: "round") -> list:
    def tf(splitted_phrase: list, words_set: set) -> dict:
        main = {key: 0 for key in words_set}
        for word in splitted_phrase:
            if not word in main:
                raise Exception("Weird error inside tf() of tf_idf()")
            main[word] += 1
        return {key: (freq / len(splitted_phrase)) for key, freq in main.items()}

    def idf(documents: list) -> dict:
        main = {}
        for _set in documents:
            for key in _set:
                if key in main:
                    main[key] += 1
                else:
                    main[key] = 1
        return {key: math.log(len(args) / freq) for key, freq in main.items()}

    splitted_phrases = [phrase_splitter(phrase) for phrase in args]
    documents = [{el for el in splitted_phrase} for splitted_phrase in splitted_phrases] #array di set
    words_set = {el for subset in documents for el in subset}
    _round = kwargs['round'] if 'round' in kwargs else 2

    _idf = idf(documents)
    result = []
    for phrase in splitted_phrases:
        _tf = tf(phrase, words_set)
        result.append({key: round(_tf[key] * _idf[key], _round) for key in words_set})

    return result

# vogliamo codificare un testo in numeri

# Bag-of-words
# conta quante occorrenze di una parola ricorrono nel documento, serve a rappresentare
# un discorso dal punto di vista di un vettore numerico.
# Lo svantaggio è che si tratta di un modello riduttivo, infatti tende a dare più
# importanza alle parole ricorrenti nella lingua, come avverbi e congiunzioni


DOCUMENT1 = "La nonna, la mamma e la zia preparano la cena per il compleanno della zia"

print("Bag-of-words:", bow_document1 := bag_of_words(DOCUMENT1))

# TF*IDF (Term Frequency for Inverse Document Frequency)
#

DOCUMENT2 = "Il papà e il nonno guardano la partita"
DOCUMENT3 = "Il leone e la gazzella si guardano"

tf_idf(DOCUMENT1, DOCUMENT2, DOCUMENT3)
