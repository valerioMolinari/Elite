class Reader:
    @classmethod
    def read(cls, path:str) -> str:
        file = open(path, 'r')
        res = file.read()
        file.close()
        return res

    @classmethod
    def readlines(cls, path:str) -> list:
        file = open(path, 'r')
        res = file.readlines()
        file.close()
        return res

    @classmethod
    def readlines_no_new_line(cls, path:str) -> list:
        file = open(path, 'r')
        res = list(map(lambda x:x[:-1], file.readlines()))
        file.close()
        return res