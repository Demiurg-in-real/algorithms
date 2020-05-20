#ifndef __DFS__
#define __DFS__
#include "base.h"
class DFS:public Base{
	private:
		std::vector<int> visited;
	public:
		virtual void dfs(size_t index);
		virtual std::vector<int>  get(){
			return visited;
		}
		DFS(std::vector<std::vector<int>> vect):Base(vect){};
};
#include "dfs.tpp"
#endif
