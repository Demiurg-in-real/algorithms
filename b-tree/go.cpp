#include "B-tree.h"
#include<iostream>
int main(){
	btree<int,int> k(2,4,5);
	int i,y;
	for(i=10,y=100; i<14000; i++, y++) k.add(i,y);
	return 0;
}
