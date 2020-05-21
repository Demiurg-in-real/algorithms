#include "floid.tpp"
#include <iostream>
using namespace std;
int main(){
	vector<vector<int>> grr(8);
	for(auto i = grr.begin(); i<grr.end(); i++)
		i->resize(8);	
	grr[0][3]=5;
	grr[0][4]=10;
	grr[1][3]=2;
	grr[1][2]=1;
	grr[2][4]=7;
	grr[2][1]=1;
	grr[3][0]=5;
	grr[3][1]=2;
	grr[3][4]=3;
	grr[3][6]=6;
	grr[4][0]=10;
	grr[4][2]=7;
	grr[4][3]=3;
	grr[4][5]=2;
	grr[4][6]=4;
	grr[4][7]=1;
	grr[5][7]=15;
	grr[5][4]=2;
	grr[6][4]=4;
	grr[6][3]=6;
	grr[7][5]=15;
	grr[7][4]=1;
	for(size_t i =0; i<grr.size(); i++){
		for(size_t j =0; j<grr[i].size(); j++){
			if(grr[i][j] == 0) grr[i][j] = 0xfffffff;
		}
	}

	floid(grr);
	for(auto i:grr){
		std::cout<<std::endl;
		for(auto j:i)
			std::cout<<j<<" ";
	}
//	vector<int> lol;
//	kek.Flori(lol);
//	auto lol = kek.get();
//	for(auto i:lol) cout<<i<<endl;
	return 0;
}
