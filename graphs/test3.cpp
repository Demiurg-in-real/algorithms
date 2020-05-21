#include "deikstra.h"
#include <iostream>
using namespace std;
int main(){
	vector<vector<vector<int>>> grr(8);
	grr[2].resize(1);
	for(int i = 0; i<grr[2].size(); i++)
		grr[2][i].resize(2);
	grr[2][0][0] = 1;
	grr[2][0][1] = 1;

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

	grr[4].resize(5);
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

	grr[5].resize(1);
	for(int i = 0; i<grr[5].size(); i++)
		grr[5][i].resize(2);
	grr[5][0][0] = 7;
	grr[5][0][1] = 15;

	Deikstra kek(grr);
	kek.dik(3);
	auto l = kek.get();
	for(auto i : l)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
