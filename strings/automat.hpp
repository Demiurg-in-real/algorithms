#ifndef __AUTOMAT__
#define __AUTOMAT__
#include<vector>
#include<string>
#include "prefix.hpp"
#include "avl/avl.h"
namespace ALGS{
	class automat{
		private:
			std::vector<AVL::tree<char,int>> graph;
			std::string subs;
			void make_graph(std::string subs);
		public:
			automat();
			void search(const std::string& str, const std::string& substr, std::vector<int>& pos);
	};
}
#endif
