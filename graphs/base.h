#ifndef __BASE__
#define __BASE__
#include<vector>
#include<utility>
class Base{
	protected:
		std::vector<std::pair<bool, std::vector<int>>> gr;
		virtual void make(std::vector<std::vector<int>> vect);
	public:
		Base(std::vector<std::vector<int>> vect);
};
#include "base.tpp"
#endif
