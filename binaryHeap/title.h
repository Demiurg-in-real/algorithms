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
		unsigned long numer = 0;
		int levels=0;
	public:
		void print();
		bool empty();
		uint64_t siz();
		kek max();
		void reset(unsigned long posit);
		void push(kek elem);
		void erase(unsigned long posit);
};
#include "realisate.tpp"
#endif
