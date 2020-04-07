'''
Write a Python program to check for access to a specified path. Test the existence, readability,
writability and executability of the specified path
'''

import os

class Access:
    @staticmethod
    def properties(path='.'):
        access = lambda mode : os.access(path, mode)
        return {
            "Path": path,
            "Exist": access(os.F_OK),
            "Readable": access(os.R_OK),
            "Writeble": access(os.W_OK),
            "Executable": access(os.F_OK)
        }


if __name__ == '__main__':
    print(Access.properties('access.py'))