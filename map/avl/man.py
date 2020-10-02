#! /usr/bin/python3
import xren
import random 

if __name__ == '__main__':
    tree = xren.Map(50,1)
    for i in range(10000):
        tree.insert_node_1(random.randint(0,1000000000),random.randint(0,1000000000))
    if tree.check():
        print("Allright!")

#	print('ssss')
#	tree.f_1(4)


#	print("Добавим : ключ: 5 , значение : 6 ")
#	tree.insert_node_1(5,6)

#	print()


#	print("Добавим : ключ: 6 , значение : 6 ")
#	tree.insert_node_1(6,6)
