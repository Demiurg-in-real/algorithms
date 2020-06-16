#ifndef _PREFIX_
#define _PREFIX_
#include <cstddef>
#include <vector>
#include <string>
namespace ALGS{
	std::size_t prefix(std::string wat);
	void prefix(std::string wat,std::vector<int>& pi);
	#include "prefix.tpp"
}
#endif
