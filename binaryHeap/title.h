#ifndef _BINARY_HEAP_
#define _BINARY_HEAP_
#include<vector>
#include<cstdint>
#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<cmath>
using std::vector;
using std::cout;
template <typename kek> class role{
	private:
		vector<kek> mass;
		void reset(unsigned long posit);
		kek erase (unsigned long posit);
	public:
		void print();
		bool empty();
		uint64_t siz();
		kek max();
		void push(kek elem);
		kek pop();
};
#include "realisate.tpp"
#endif
