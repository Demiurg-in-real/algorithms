#include<vector>
#include<iostream>
//#include "node.h"
using namespace std;
int main(){
	vector<int> kek;
	kek.resize(10);
	cout<<kek.size()<<endl;
	kek[0] = 4;
	cout<<kek.size()<<" - "<<kek[0]<<endl;
//	kek.insert(kek.begin(),5 );
//	kek.insert(kek.begin(),10);
	cout<<kek.size()<<endl;
	int c=30;
	for(unsigned int i=kek.size()-1; i != (-1); i--, (c-=2)) {
		kek[i] = c;
		cout<<kek[i]<<" ";
	}
	cout<<kek[10]<<endl;
	int i=9;
	if(7<kek[i])cout<<"Mde"<<endl;
//	i=10;
//	while( i>=0 && 32<kek[i])i--;
//	i++;
	for(i=10; i>=0 && 16<=kek[i-1]; i--) cout<<kek[i]<<" "<<i<<" - hm"<<endl;
//	for(i = 0; i<3 && kek[i] != 5; i++){
//		cout<<kek[i]<<" ";
//	}
	cout<<endl;
	kek.erase(kek.begin()+0);
	for(int y=0; y<kek.size();y++) cout<<kek[y]<<" ";
	cout<<endl<<kek[i]<<" = "<<i<<endl;
	for(i=9;i>=9;i--) cout<<"Mean of i in cycle:"<<i<<endl;
	cout<<"ist - "<<i<<endl;
	for((int i=0;short c = 3); i<3; i++, c*=c) cout<<c<<endl;
//	vector<node<int>*> lol;
//	lol.resize(3);
//	if(lol[1] == NULL)cout<<"Kekov\n";
	return 0;
}	
