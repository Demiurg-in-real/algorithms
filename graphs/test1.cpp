#include "dfs.h"
#include <iostream>
using namespace std;
int main(){
	vector<vector<int>> grr(7);
	grr[0].push_back(4);
	grr[1].push_back(0);
	grr[1].push_back(3);
	grr[2].push_back(1);
	grr[3].push_back(2);
	grr[4].push_back(3);
	grr[4].push_back(5);
	grr[4].push_back(6);
	DFS kek(grr);
	kek.dfs(4);
	auto lol = kek.get();
	for(auto i:lol) cout<<i<<endl;
	return 0;
}
