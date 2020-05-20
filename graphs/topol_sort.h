#ifndef __TOPOLOGICAL_SORT__
#define __TOPOLOGICAL_SORT__
#include <stack>
#include "base.h"
class topol_sort:public Base{
	private:
		std::vector<int> sorted;
		void dfs_m(std::stack<int>& q, int index);
	public:
		topol_sort(std::vector<std::vector<int>> vect):Base(vect){};
		void topological_sort();
		std::vector<int> get(){
			return sorted;
		}
};
#include "topol_sort.tpp"
#endif
