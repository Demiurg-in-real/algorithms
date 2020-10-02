#! /usr/bin/python3
import brevno

if __name__ == '__main__':
	

# это первый элемент, который положим 
#в root.keys. Похже он будет лежать 
#в др месте в соот-и с правилами сортировки 
# в дереве


    btree = brevno.Btree(2,1,4)
    btree.insert(5,2)
    btree.insert(4,7)
    btree.insert(10,11)
    for i in range(1000000):
        btree.insert(i, (i * i))
    print(btree.root.children[1].keys[0])
    btree.clear_all()
#    print(btree.root.children[0].keys[0])
	#btree.insert(3,2)

#	for i in range(3):
#		btree.insert(i,i)

