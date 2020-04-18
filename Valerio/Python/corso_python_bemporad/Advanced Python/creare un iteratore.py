class MyIterator:
    def __iter__(self):
        self.__myattr = 2
        return self

    def __next__(self):
        if self.__myattr < 300:
            n = self.__myattr
            self.__myattr *= 2
            return n
        else:
            raise StopIteration

MyClass = MyIterator()
iterator = iter(MyClass)
print(iterator)
try:
    while True:
        print(next(iterator))
except StopIteration:
    print("*** limit bound exceded ***\n")

# Poiché iterator è di fatto un iteratore, il costrutto for in si comporta bene stampando tutti
# gli elementi senza sollevare l'eccezione

MyClass = MyIterator()
iterator = iter(MyClass)

for target in iterator:
    print(target)