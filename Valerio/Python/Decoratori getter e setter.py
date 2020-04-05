# I getter e i setter possono essere ottenuti tramite due decoratori, @property e @[name].setter,
# che permettono di creare rispettivamente un getter e un setter bypassando l'aliasing

class MyClass:
    def __init__(self, my_attr):
        self.__priv_attr = my_attr

    @property
    def attr(self):
        return self.__priv_attr

    @attr.setter
    def attr(self, my_attr):
        self.__priv_attr = my_attr

m1 = MyClass("mariottide")
print(m1.attr)