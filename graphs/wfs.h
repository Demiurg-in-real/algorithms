#ifndef __WFS__
#define __WFS__
#include <stack>
#include "base.h"
class WFS:public Base{
	private:
		std::vector<int> visited;
	public:
		std::vector<int> get(){
			return visited;
		}
		WFS(std::vector<std::vector<int>> vec):Base(vec){};
		void wfs(size_t start);
};
#include "wfs.tpp"
#endif
