'''
Write a Python program to get the name of the operating system (Platform independent),
information of current operating system, current working directory,
print files and directories in the current directory and raises error
in the case of invalid or inaccessible file names and paths
'''

import os
from colors import red_lit

os_name = os.name
infos = os.uname()
currentDir = os.getcwd()
content = os.listdir()

print("Sistema operativo:\n\t"+os_name)
print("Informazioni sul sistema:\n\t"+'\n\t'.join(infos))
print("Cartella attuale:\n\t"+currentDir)
print(f"Contenuto cartella:\n\t{content}")
try:
    filename = 'abc.py'
    file = open(filename, 'r')
    content = file.read()
    file.close()
    print(content)
except IOError:
    red_lit(f"\nNot access or problem in reading: {filename}")
