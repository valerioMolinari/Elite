from os import *
import platform
from colors import *

# nome della macchina
print(name)
# sistema operativo sulla piattaforma
print(platform.system())
# data di rilascio della piattaforma
print(platform.release())


# Comandi utili

#   environ: è una mappatura delle informazioni dell'ambiente di runtime e sulla shell

green("\nos.environ")
flag = False
for key, value in environ.items():
    if(flag):
        print("\x1b[33m", end = '')
    print(f"\"{key}\" : \"{value}\"")
    print("\x1b[0m", end='')
    flag = not flag

#   getcwd(): restituisce la cartella di esecuzione sul terminale, come process.cwd() in js
#             equivale a environ['PWD']

green("\nos.getcwd()")
current_folder = getcwd()
print(f"Percorso corrente: {current_folder}")

#   chdir(path): cambia il percorso della cartella operativa della shell del programma

green("\nos.chdir(path)")
chdir(environ['HOME'])
print("Cambio il percorso della cartella sfruttando environ['HOME'] per andare nella cartella di avvio:")
yellow(f"\tPercorso corrente: {getcwd()}")
chdir(current_folder)
print("Ritorno nella cartella da cui è partito il progetto:")
yellow(f"\tPercorso corrente: {getcwd()}")

#   geteuid(): solo su Unix, restituisce l'id del processo attuale

green("\nos.geteuid()")
current_process_id = geteuid()
print("ID del processo attuale: ", end='')
yellow(current_process_id)

#   getpid(): restituisce il pid del processo attuale

green("\nos.getpid()")
current_process_pid = getpid()
print("PID del processo attuale: ", end='')
yellow(current_process_pid)

#   getlogin(): restituisce il nome dell'user che sta eseguendo il programma

green("\nos.getlogin()")
user = getlogin()
print("User: ", end='')
yellow(user)

# Comandi avanzati

# os.fsencode(filename)
# os.fsdecode(filename)
# os.fspath(path)
# class os.PathLike
# os.getenv(key, default=None)
