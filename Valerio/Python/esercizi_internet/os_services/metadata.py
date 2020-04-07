'''
Write a Python program to get the size, permissions, owner, device, created,
last modified and last accessed date time of a specified path
'''

import os
import time

class Metadata:
    @staticmethod
    def get_data(path='.'):
        stat_info = os.stat(path)
        return {
            'path': path,
            'size': os.path.getsize(path),
            'permission': oct(stat_info.st_mode)[-3:],
            'owner': stat_info.st_uid,
            'device': stat_info.st_dev,
            # time.ctyme() converte in una data il numero di millisecondi dal 1/1/1970 (detta l'epoca 😮)
            'Created': time.ctime(stat_info.st_ctime),
            'Last modified': time.ctime(stat_info.st_mtime),
            'Last accessed': time.ctime(stat_info.st_atime)
        }

if __name__ == '__main__':
    print(Metadata.get_data())