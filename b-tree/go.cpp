#include "B-tree.h"
#include<iostream>
#include<stdio.h>
int main(){
	btree<int,int> k(2,4,5);
	int i,y;
	for(i=10,y=100; i<100000; i++, y++) k.add(i,y);
	std::cout<<"way\n";
	std::cout<<k.root->child[0]->child[1]->items[0]->key<<" heh"<<std::endl;
//	printf("%p\n",kek->child[0]);
	return 0;
}
