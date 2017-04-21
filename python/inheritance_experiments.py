""" Experiments with classes and super(). 

This script explored the relationship between a class, its
instance, and the class resolution order. 

Krzysztof Chalupka, 2017.
"""

class Adict(dict):
    def msg(self):
        print('a')

    def __setitem__(self, key, val):
        self.msg()
        print('insert a')
        super(Adict, self).__setitem__(key, val)

class Bdict(dict):
    def msg(self):
        print('b')

    def __setitem__(self, key, val):
        self.msg()
        print('insert b')
        super(Bdict, self).__setitem__(key, val)

class Cdict(Adict):
    def __setitem__(self, key, val):
        print('c')
        print('insert c')
        super(Cdict, self).__setitem__(key, val)


class Cdict2(Adict):
    def msg(self):
        print('c2')

    def __setitem__(self, key, val):
        self.msg()
        print('insert c2')
        super(Cdict2, self).__setitem__(key, val)

class Ddict(Adict, Bdict):
    def msg(self):
        print('d')

    def __setitem__(self, key, val):
        self.msg()
        print('insert d')
        super(Ddict, self).__setitem__(key, val)

class AdictMangled(dict):
    def __msg(self):
        print('a')

    def __setitem__(self, key, val):
        self.__msg()
        print('insert a')
        super(AdictMangled, self).__setitem__(key, val)

class BdictMangled(AdictMangled):
    def __msg(self):
        print('b')

    def __setitem__(self, key, val):
        self.__msg()
        print('insert b')
        super(BdictMangled, self).__setitem__(key, val)

if __name__=="__main__":
    """ Prints 'a', 'insert a'. """
    d = Adict([(1, 1)])
    d[2] = 2
    print('----------------------------')
    
    """ Prints 'b', 'insert b'. """
    d = Bdict([(1, 1)])
    d[2] = 2
    print('----------------------------')
    
    """ Prints 'c', 'insert c', 'a', 'insert a'. """
    d = Cdict([(1, 1)])
    d[2] = 2
    print('----------------------------')
    
    """ Prints 'c2', 'insert c2', 'c2', 'insert a'.
    This is because C2dict calls Adict's __setitem__, but the 
    self passed to Adict.__setitem__ is an instance of Cdict2,
    that is self.msg() is C2dict's instance method. """
    d = Cdict2([(1, 1)])
    d[2] = 2
    print('----------------------------')

    """ Prints 'd', 'insert d', 'd', 'insert a', 'd', 'insert b'.
    Each 'd' comes from Ddict instance's self.msg(). The __setitem__
    method, in turn, is being passed down the inheritance chain."""
    d = Ddict([(1, 1)])
    d[2] = 2
    print('----------------------------')

    """ Prints 'b', 'insert b', 'a', 'insert a'. In this case, the
    self.__msg instance method is mangled, so it behaves as expected."""
    d = BdictMangled([(1, 1)])
    d[2] = 2
