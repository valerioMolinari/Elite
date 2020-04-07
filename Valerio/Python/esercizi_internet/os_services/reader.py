'''
Write a Python program to list only directories, files and all directories, files in a specified path
'''

import os
import sys

class Reader:
    '''
    Con os.path si può accedere a verificatori che permettono di stabilire se il percorso di
    un elemenento corrisponde ad un file o una cartella, con i metodi isdir() e isfile().
    Utilizziamo os.path.join(path, name) per creare l'intero percors fino al nome dell'elemento.
    os.listdir([,path]) elenca il contenuto di una cartella, se non viene specificata
    quale, la cartella è la current working directory (cwd)
    '''
    __default = lambda path, condition: [el for el in os.listdir(path) if condition(os.path.join(path, el))]

    @classmethod
    def dirs(cls, path = '.'):
        return cls.__default(path, os.path.isdir)

    @classmethod
    def files(cls, path = '.'):
        return cls.__default(path, os.path.isfile)

    @staticmethod
    def all(path = '.'):
        return os.listdir(path)

# Eseguo il codice di test solo se sto eseguendo questo script
if __name__ == '__main__':
    home = os.environ["HOME"]
    path = '.' or sys.argv[1]

    print("Contenuto:",Reader.all(path))
    print("File:",Reader.files(path))
    print("Cartelle:",Reader.dirs(path))
