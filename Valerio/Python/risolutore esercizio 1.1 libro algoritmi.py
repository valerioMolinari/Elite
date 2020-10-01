from decimal import Decimal
import math

def res(callback):
    def f(n, callback):
        return f"{Decimal(callback(n*1e6)):.1E}"
    t = {"s"  :1,
        "min" :60,
        "h"   :60 ** 2,
        "d"   :60 ** 2 * 24,
        "mon" :60 ** 2 * 24 * 30,
        "y"   :60 ** 2 * 24 * 30 * 365,
        "c"   :60 ** 2 * 24 * 30 * 365 * 100
        }
    for _t in t:
        print(f"{_t}: {f(t[_t], callback)}")

def aprox(n, callback):
    t = 2
    e = 0
    while callback(t) < n:
        e += 1
        t = 2**e

    while True:
        if e > 0:
            e -= 1
            if callback(t) < n:
                t += 2**e
            elif callback(t) > n:
                t -= 2**e
            else:
                return t
        else:
            if callback(t) < n:
                t += 1
                if callback(t) > n:
                    return t - 1
            elif callback(t) > n:
                t -= 1
                if callback(t) < n:
                    return t
            else:
                return t
    return t

def fattoriale(n):
    fat = 1
    while n > 1:
        fat *= n
        n -= 1
    return fat


res(lambda x : aprox(x, lambda x: x * math.log2(x)))
