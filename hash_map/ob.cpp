#include"hash_map.h"

int main(){
	part_tree::hash_map<int, int> kek;
	for(int i=0;i<3000;i++) {
		kek.insert(i, i+10);
	}
/*	kek.print();
	std::cout<<"\n";
	kek.delet(2);
	kek.print();
	std::cout<<"\n";
	kek.insert(0,123456);
	kek.print();
	std::cout<<"\n";
	kek.insert(1000,1221);
	kek.print();
	std::cout<<"\n";
	kek.insert(212,4124);
	kek.print();
//	std::cout<<kek.size()<<std::endl;*/
	return 0;
}
