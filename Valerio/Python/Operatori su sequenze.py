# Sulle stringhe utilizzando le parentesi quadre si estrarre un carattere

s = "python programming"

print(s[0]) # p
print(s[8]) # r

# Si può poi usare il carattere : per creare uno slice

print(s[:]) # python programming
print(s[1:4]) # yth
print(s[:4]) # pyth
print(s[9:]) # ogramming
print(s[1:12:3]) # yopg: caratteri da 1 a 12 saltando 3 per volta
print(s[-2:]) # ng: da lunghezza - 2 fino a lunghezza

# concatenazione

n = 'Valerio '
c = 'Molinari'
nc = n + c
print(nc)

# Lunghezza, minimo, massimo

print(len(nc)) # 16
print(min(c)) # M
print(max(c)) # r