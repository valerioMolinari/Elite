from random import randint
from time import time

def max_sub_array(a):
    change = [0]
    max = 0
    maxIndex = ()
    sums = []
    for i in range(len(a) - 1):
        if a[i] * a[i + 1] < 0:
            change.append(i + 1)
    change.append(len(a))
    for i in range(len(change) - 1):
        sum = 0
        for j in range(change[i], change[i + 1]):
            sum += a[j]
        sums.append(sum)
    for i in range(len(sums)):
        sum = 0
        for j in range(i, len(sums)):
            sum += sums[j]
            if sum > max:
                max = sum
                maxIndex = (change[i],change[j + 1])

    return a[maxIndex[0]:maxIndex[1]]


a = [randint(-100,100) for i in range(50000)]

t = -time()
max_sub_array(a)
t += time()

print(t)
