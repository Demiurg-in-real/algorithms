#include<cstdio>
#include<cstdint>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;
int main(){
	string kek = "lol";
	if(typeid(string) == typeid(kek))printf("Lol\n");
	short i;
	uint8_t one[4]={32,44, 32,45};
	i = *((long long*)one) ^ (*((long long*)(one+2)));
	printf("%hi\n",*((short*)(one+2)));
	vector<int> kkk(1);
	vector<int> kkl(2);
	kkl[0]=3210;
	kkl[1]=3456;
	kkk[0] = 1000;
	kkk=kkl;
	double fe = 8/3;
	printf("%i %i\n%f", kkk[0],kkk[1], (double)(1111111111111111111));
	return 0;
}
