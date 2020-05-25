#include "krusk.h"
#include <iostream>
using namespace std;
int main(){
	vector<vector<vector<int>>> grr(8);
	grr[0].resize(2);
	for(int i = 0; i<grr[0].size(); i++)
		grr[0][i].resize(2);
	grr[0][0][0] = 3;
	grr[0][0][1] = 5;
	grr[0][1][0] = 4;
	grr[0][1][1] = 10;

	grr[1].resize(2);
	for(int i = 0; i<grr[1].size(); i++)
		grr[1][i].resize(2);
	grr[1][0][0] = 3;
	grr[1][0][1] = 1;
	grr[1][1][0] = 2;
	grr[1][1][1] = 1;

	grr[2].resize(2);
	for(int i = 0; i<grr[2].size(); i++)
		grr[2][i].resize(2);
	grr[2][0][0] = 1;
	grr[2][0][1] = 1;
	grr[2][1][0] = 4;
	grr[2][1][1] = 7;

	grr[3].resize(4);
	for(int i = 0; i<grr[3].size(); i++)
		grr[3][i].resize(2);
	grr[3][0][0] = 0;
	grr[3][0][1] = 5;
	grr[3][1][0] = 1;
	grr[3][1][1] = 1;
	grr[3][2][0] = 4;
	grr[3][2][1] = 3;
	grr[3][3][0] = 6;
	grr[3][3][1] = 6;

	grr[4].resize(6);
	for(int i = 0; i<grr[4].size(); i++)
		grr[4][i].resize(2);
	grr[4][0][0] = 0;
	grr[4][0][1] = 10;
	grr[4][1][0] = 2;
	grr[4][1][1] = 7;
	grr[4][2][0] = 5;
	grr[4][2][1] = 2;
	grr[4][3][0] = 6;
	grr[4][3][1] = 4;
	grr[4][4][0] = 7;
	grr[4][4][1] = 1;
	grr[4][5][0] = 3;
	grr[4][5][1] = 3;

	grr[5].resize(2);
	for(int i = 0; i<grr[5].size(); i++)
		grr[5][i].resize(2);
	grr[5][0][0] = 7;
	grr[5][0][1] = 15;
	grr[5][1][0] = 4;
	grr[5][1][1] = 2;

	grr[6].resize(2);
	for(int i = 0; i<grr[6].size(); i++)
		grr[6][i].resize(2);
	grr[6][0][0] = 3;
	grr[6][0][1] = 6;
	grr[6][1][0] = 4;
	grr[6][1][1] = 4;

	grr[7].resize(2);
	for(int i = 0; i<grr[7].size(); i++)
		grr[7][i].resize(2);
	grr[7][0][0] = 5;
	grr[7][0][1] = 15;
	grr[7][1][0] = 4;
	grr[7][1][1] = 1;
	
		
		

	for(size_t i = 0; i<grr.size(); i++){
		for(size_t j = 0; j<grr[i].size(); j++){
			std::cout<<i<<" "<<grr[i][j][0]<<" "<<grr[i][j][1]<<std::endl;
		}
		std::cout<<std::endl;
	}
	kruskal kek;
       	kek.make(grr);
	kek.krask();
	auto l = kek.get();
	for(auto i : l){
		for (auto c:i)
			std::cout<<c<<" ";
		std::cout<<std::endl;
	}
}
