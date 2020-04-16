from menu import Menu

def menu_pricipale():
    scelta_menu_principale = ''
    while scelta_menu_principale != 'salva ed esci':
        scelta_menu_principale = Menu(('start', 'salva ed esci'), head="Menu principale").raw_menu()
        if scelta_menu_principale == 'start':
            scelta_menu_principale = start(scelta_menu_principale)
    salva()

def start(scelta_precedente):
    while True:
        scelta_menu_start = Menu(('cucina', 'fai una passeggiata', 'lavati'), head="Menù di start").full_menu()
        if scelta_menu_start == 'salva ed esci':
            return 'salva ed esci'
        if scelta_menu_start == 'torna indietro':
            return scelta_precedente
        if scelta_menu_start == 'lavati':
            lavati()

def lavati():
    input("\x1b[32mScrivi una roba qualsiasi quindi torna indietro: \x1b[0m")

def salva():
    print("Dati salvati nel database")

menu_pricipale()
