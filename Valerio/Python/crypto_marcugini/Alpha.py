class Alpha:
    def __init__(self, dictionary:dict):
        self.__dictionary = dictionary

    def sort(self, direction:str) -> dict:
        if direction != 'ascending' and direction != 'descending':
            raise Exception("direction must be ascending or descending")
        return dict(sorted(self.__dictionary.items(), key=lambda x:x[1], reverse=(False if direction == 'ascending' else True)))

    def stringAlpha(self):
        return ''.join(list(self.__dictionary.values()))

    @property
    def dictionary(self):
        return self.__dictionary