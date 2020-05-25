a = [i for i in range(10)]
b = [i for i in range(50, 150, 10)]
c = [i for i in range(0, 1000, 100)]

for i, j, k in zip(a, b, c):
    print(i, j, k)
print()

a = [[j for j in range(i * 10, i * 10 + 10)] for i in range(10)]
a

for q in a:
    print(q)
print()

for q, w, e, r, t, y, u, i, o, p in a:
    print(q, w, e, r, t, y, u, i, o, p)
