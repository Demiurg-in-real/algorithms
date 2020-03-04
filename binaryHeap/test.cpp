#include "title.h"
int main(){
	role<uint8_t> lol;
	uint8_t buf[1];
	uint8_t buk[31];
	int k = open("/dev/random", O_RDONLY);
	if(k == -1) perror("open");
	for(int i=0; i<31;i++){
		read(k,buf,1);
		lol.push(*buf);
		buk[i] = *buf;
	}
	for(int i = 0; i<31; i++)printf("%i, ", buk[i]);
	cout<<std::endl;
	close(k);
	lol.print();
	lol.erase(0);
	lol.print();
	return 0;
}
