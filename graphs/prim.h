#ifndef __PRIM__
#define __PRIM__
#define _PRIM__INF_ 1000000
#include <iostream>
#include <vector>
#include <utility>
class Prim{
	private:
		std::vector<std::vector<std::vector<int>>> gr;
		std::vector<std::pair<int,int>> result;
		bool check_bd(std::vector<std::vector<std::vector<int>>>& vect);
	public:
		void make(std::vector<std::vector<int>> vect);
		void make(std::vector<std::vector<std::vector<int>>> vect);
		std::vector<std::pair<int,int>> get(){
			return result;
		}
		void prim();
};
#include "prim.tpp"
#endif
