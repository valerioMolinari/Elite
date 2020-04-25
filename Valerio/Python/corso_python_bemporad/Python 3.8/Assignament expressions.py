# Warlus operator -> :=
# warlus in inglese significa tricheco, infatti agli sviluppatori quel simbolo
# ha ricordato gli occhi e le zanne di un tricheco :)
#
# Chiusa parentesi simpatica l'utilità dell'operatore è quella di fare un assegnamento
# all'interno di un'espressione come nell'esempio

def somma(x: int, y: int) -> int:
    return x + y

if (x := somma(3, 9)) > 10:
    print(f"{x} è maggiore di dieci")