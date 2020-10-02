import copy as cp
class Node:

    key = None
    height = 1
    balance = 0
    value = None
    leftChild = None
    rightChild = None

    def __init__(self , key , value ):
        self.leftChild = None
        self.rightChild = None
        self.key = key
        self.value = value

    def __iter__(self):
        if self.leftChild:
            for p in self.leftChild:
                yield p
        yield p
        if self.rightChild:
            for p in self.rightChild:
                yield p

class Map:
    root = None
    def __init__(self , key, value):
        self.root = Node(key, value)
	
    def insert_node_1(self, key , value):
        self.root = self.insert_node(self.root,key,value)
    def insert_node(self,p,key,value):
        if p == None:
            c = Node(key,value)
            return c
        if p.key < key:
            p.rightChild = self.insert_node(p.rightChild,key,value)
        elif p.key>key:
            p.leftChild = self.insert_node(p.leftChild,key,value)
        elif p.key == key:
            p.value = value
        return self.balance_node(p)
    def height(self , p):
        if p is None:
            return 0
        else:
            return p.height

    def balance_factor(self , p):
        return self.height(p.leftChild) - self.height(p.rightChild)

    def fix_height(self , p):
        if(self.height(p.rightChild) >= self.height(p.leftChild)):
            p.height = 1 + self.height(p.rightChild)
        else:
            p.height = 1 + self.height(p.leftChild)

    def rotate_right(self , a):
        b = a.leftChild  
        x = b.rightChild                                        
        b.rightChild = a        
        a.leftChild = x  
        self.fix_height(a)
        self.fix_height(b)
#                Можно ещё сделать ещё так:
#        b = a.leftChild
#        a.leftChild = b.rightChild
#        b.rightChild = a
#        self.fix_height(b.rightChild)
#        self.fix_height(b)
        return b
    def rotate_left(self , a):
        b = a.rightChild
        x = b.leftChild             
        b.leftChild = a       
        a.rightChild = x
        self.fix_height(a)
        self.fix_height(b)
        '''Можно сделать ещё так:
        b = a.rightChild
        print(str(a)+" - hm")
        a.rightChild = b.leftChild
        b.leftChild = a
        self.fix_height(b.leftChild)
        self.fix_height(b)
        '''
        return b

    def balance_node(self , p):
        self.fix_height(p)
        if self.balance_factor(p) == -2 :
            if self.balance_factor(p.rightChild) > 0:
                p.rightChild = self.rotate_right(p.rightChild)
            return self.rotate_left(p)
        elif self.balance_factor(p) == 2:
            if self.balance_factor(p.leftChild) < 0:
                p.leftChild = self.rotate_left(p.leftChild)
            return self.rotate_right(p)
        return p


    def find_min_node(self , p):
        return self.find_min_node(p.leftChild) if p.leftChild else p
    def delete_1(self , key ):
        if self.empty():
            if self.find_key(self.root,key):
                self.root = self.delete_ob(self.root,key)
    def delete_ob(self, p , key):
        if key < p.key:
            p.leftChild = self.delete_ob(p.leftChild , key)
        elif key > p.key:
            p.rightChild = self.delete_ob(p.rightChild , key)
        else:
            if p is None:
                return p
            if p.rightChild == None and p.leftChild == None:
                return None
            elif p.leftChild is None:
                return p.rightChild
            elif p.rightChild is None:
                return p.leftChild
            minn = self.find_min_node(p.rightChild)
            neW = Node(minn.key,minn.value)
            neW.rightChild = p.rightChild
            neW.leftChild = p.leftChild
            neW.rightChild = self.delete_ob(neW.rightChild , minn.key)
            return self.balance_node(neW)
        return self.balance_node(p)


    def search(key):
        return find_key(self.root,key)

    def find_key(self, p, key):
        if p == None:
            return None
        if key == p.key:
            return p
        elif key<p.key:
            return self.find_key(p.leftChild,key)
        elif key>p.key:
            return self.find_key(p.rightChild,key)

    def empty(self):
        if self.root == None:
            return False
        return True

    def printf_1(self,p,level):
        if p.rightChild:
            self.printf_1(p.rightChild, level+1)
        print("-"*level+str(p.key))
        if p.leftChild:
            self.printf_1(p.leftChild,level+1)

    def prin(self):
        print("Printing tree")
        if self.empty != None:
            self.printf_1(self.root,0)
        else:
            print("Tree is empty")


    def tree_height(self,nd):
        if nd == None:
            return True
        self.tree_height(nd.leftChild)
        self.tree_height(nd.rightChild)
        if self.balance_factor(nd) < (-2) or self.balance_factor(nd)>2:
            return False
        else:
            return True

    def check(self):
        return self.tree_height(self.root)
