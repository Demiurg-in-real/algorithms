#include"hash_map.h"
#include<iostream>	

int main(){
	part_tree::hash_map<int, int> kek;
	for(int i=0;i<10000;i++) {
		std::cout<< i<<std::endl;
		kek.insert(i, i+10);
	}
	std::cout<<kek.size()<<std::endl;
	return 0;
}
