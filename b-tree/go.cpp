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
	kek->size=3;
	for(i=0; i<kek->size;i++)std::cout<<kek->items[i]->key<<"   "<<kek->items[i]->value<<std::endl;
	node<int,int> *lol = new node<int,int>(2);
	lol->leaf=false;
	lol->child[0] = kek;
	k.split(kek,lol,0);
	for(i=0; i<lol->size;i++)std::cout<<lol->items[i]->key<<" - "<<lol->items[i]->value<<"; ";
	return 0;
}
