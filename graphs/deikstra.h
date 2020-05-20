#ifndef __DEIKSTRA__
#define __DEIKSTRA__
#include<vector>
#include<utility>
class Deikstra{
	private:
		std::vector<std::vector<std::vector<int>>> gr;
		std::vector<std::pair<bool,int>> ways;
		std::vector<int> long_ways;
	public:
		Deikstra(std::vector<std::vector<std::vector<int>>> graph);
		void dik(size_t now);
		std::vector<int> get();
};
#include "deikstra.tpp"
#endif
