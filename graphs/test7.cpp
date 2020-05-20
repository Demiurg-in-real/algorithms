#include "topol_sort.h"
#include <iostream>
using namespace std;
int main(){
	vector<vector<int>> grr(8);
	grr[1].push_back(4);
	grr[1].push_back(6);
	grr[2].push_back(7);
	grr[3].push_back(7);
	grr[3].push_back(4);
	grr[4].push_back(5);
	grr[7].push_back(0);
	grr[7].push_back(5);
	grr[7].push_back(6);
	topol_sort kek(grr);
	kek.topological_sort();
	auto lol = kek.get();
	for(auto i:lol) cout<<i<<endl;
	return 0;
}
