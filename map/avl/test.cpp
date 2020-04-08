#include "avl.h"
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdint.h>
int main(){
	AVL::tree<uint16_t,uint16_t>* lol = new AVL::tree<uint16_t,uint16_t>(0,0);
	int fd = open("/dev/urandom", O_RDONLY);
	uint16_t first,sec;
	for(int i=0;i<100000;i++){
		read(fd, &first,2);
		read(fd, &sec,2);
		lol->insert(first,sec);
	}
	lol->insert(0,500);
	lol->delete_item(0);
	lol->print();
	lol->~tree();
	delete lol;
	close(fd);
	return 0;
}

