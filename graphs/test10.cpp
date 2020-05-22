#include "kosarau.h"
#include <iostream>
using namespace std;
int main(){
	vector<vector<int>> grr(8);
	grr[0].push_back(3);
//	grr[0].push_back(4);
//	grr[1].push_back(3);
	grr[1].push_back(2);
	grr[2].push_back(1);
	grr[2].push_back(4);
	grr[3].push_back(0);
//	grr[3].push_back(1);
	grr[3].push_back(4);
//	grr[3].push_back(6);
//	grr[4].push_back(0);
	grr[4].push_back(3);
//	grr[4].push_back(6);
	grr[4].push_back(2);
//	grr[4].push_back(5);
//	grr[4].push_back(7);
	grr[5].push_back(6);
	grr[5].push_back(7);
	grr[6].push_back(7);
	grr[6].push_back(5);
	grr[7].push_back(6);
	grr[7].push_back(5);

	kosa kek(grr);
	kek.kesa();
	auto lol = kek.get(true);
	for(auto i:lol){
		std::cout<<std::endl;
		for(auto j:i)
			cout<<j<<" ";
	}
	return 0;
}
