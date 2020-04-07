import os

class DirScanner:
    @staticmethod
    def read(path='.'):
        result = {}
        for entry in os.scandir(path):
            name = entry.name
            if entry.is_dir():
                result[entry.name] = 'dir'
            elif entry.is_file():
                result[entry.name] = 'file'
            elif entry.is_symlink():
                result[entry.name] = 'link'
            else:
                result[entry.name] =  'unknown'

        return result

if __name__ == '__main__':
    print(DirScanner.read())
