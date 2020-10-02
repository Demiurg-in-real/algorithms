class Node(object):
    keys = []
    children = []
    t = None
    leaf = None
    size = None
    def __init__(self, param):
        self.leaf = True
        self.t = param
        self.size = 0
        self.keys = [None for i in range(2 * self.t - 1) ]
        self.children = [None for i in range(2 * self.t) ]

class Btree(object):
    root = None 
    t = None
    def __init__(self , step,  key , value):
        self.t = step
        self.root = Node(self.t)
        self.root.keys[0] = [key , value]
        self.root.size = 1

    def search(self, node , key):
        if node == None:
            return None
        for i in range(node.size-1 , -1, -1):
            if key>node.keys[i][0]:
                return search(node.children[i+1], key)
            elif key == node.keys[i][0]:
                return node.keys[i]
            elif i == 0:
                return search(node.children[0], key)

    def insert(self , key , value):
        if self.root == None:
            self.root = Node(self.t)
            self.root.keys[0] = [ key , value ]
            self.root.size = 1
        elif self.root.size == ( 2 * self.t ) - 1:
            newroot = Node(self.t)
            newroot.leaf = False
            cn = self.root#mb ponadobitsa cope.deepcopy
            self.root = newroot
            newroot.children[0] = cn
            self.split_node(cn,0, newroot)
            self.insent_nonfull(key, value, newroot)
        else:
            self.insent_nonfull( key, value, self.root)

    def split_node(self, started_node, index, parent):
        z = Node(self.t)
        for i in range(self.t-1):
            z.keys[i] = started_node.keys[i + self.t]
            z.size+=1
            started_node.keys[i + self.t] = None
            started_node.size-=1
        if not started_node.leaf:
            for i in range(self.t):
                z.children[i] = started_node.children[i + self.t]
                started_node.children[i + self.t] = None
        for i in range(parent.size, index, -1):
            parent.keys[i] = parent.keys[i - 1]
            parent.children[i + 1] = parent.children[i]
        parent.keys[index] = started_node.keys[self.t - 1]
        started_node.keys[self.t - 1] = None
        parent.children[index + 1] = z
        parent.size+=1
        started_node.size-=1
        z.leaf = started_node.leaf

    def insent_nonfull(self, key,value, started_node):
        i = started_node.size - 1
        if started_node.leaf:
            while i >= 0 and key < started_node.keys[i][0]:
                started_node.keys[i + 1] = started_node.keys[i]
                i-=1
            started_node.keys[i + 1] = [key , value]
            started_node.size+=1
        else:
            while i >= 0 and key < started_node.keys[i][0]:
                i-=1
            i+=1
            if started_node.children[i].size == (2 * self.t) - 1:
                self.split_node(started_node.children[i], i, started_node)
                if key > started_node.keys[i][0]:
                    i +=1           
            self.insent_nonfull(key , value, started_node.children[i])

    def get(self,key):
        k = search(self.root, key)
        if k != None:
            return k[1]
        else:
            return None

    def is_empty(self):
        if self.root:
            return True
        elif self.root.keys[0]:
            return True
        else:
            return False

    def clear(self, nod):
        for i in range(nod.size+1):
            if nod.children[0].leaf:
                del nod.children[0]
            else:
                self.clear(nod.children[0])
                del nod.children[0]
        nod.leaf = True

    def clear_all(self):
        self.clear(self.root)
        del self.root
