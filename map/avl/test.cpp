#include "avl.h"
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdint.h>
int main(){
	AVL::tree<int32_t,int32_t> lol/* = new AVL::tree<uint16_t,uint16_t>*/(0,0);
	int fd = open("/dev/urandom", O_RDONLY);
	int32_t first,sec;
	for(int i=0;i<10000000;i++){
		read(fd, &first,1);
		read(fd, &sec,1);
		lol.insert(first,sec);
	}
//	std::cout<<(lol[1])<<" "<<lol[10000000-1]<<std::endl;
//	lol->print();
//	lol->clear_all();
//	lol.insert(0,743);
	lol.insert(1,432);
	AVL::tree<int32_t, int32_t> kek(lol);
	AVL::tree<int32_t, int32_t> kEk(14,23);
	std::cout<<"-----------------------------\n";
	kEk.print();
	kEk = lol;
	std::cout<<"-----------------------------\n";
	kek.print();
	std::cout<<"-----------------------------\n";
	lol.insert(0,999);
	lol.print();
	std::cout<<"----------------------------------------\n";
	std::cout<<lol[0]<<" - "<<lol[1]<<std::endl;
	lol.print();
//	std::cout<<"А вот сейчас начнётся реальное представление - первый в жизни итератор\n";
//	for( AVL::iterat<int32_t,int32_t> i = lol.begin(); ;i++) std::cout<<*i<<std::endl;
//	delete lol;
	close(fd);
	return 0;
}

