#ifndef __KRUSKAL__
#define __KRUSKAL__
#include <vector>
#include <utility>
class kruskal{
	private:
		int parthoar(std::vector<std::vector<int>>& kek, int low, int high);
		void qsort(std::vector<std::vector<int>>& kek, int low, int high);
		std::vector<std::vector<int>> versh;
		std::vector<std::pair<bool, std::vector<std::vector<int>>>> gr;
		bool bedirected;
	public:
		void krask();
		void make(std::vector<std::vector<std::vector<int>>> vect, bool bd);
		std::vector<std::vector<int>> get(){
			return versh;
		}
};
#include "krusk.tpp"
#endif
