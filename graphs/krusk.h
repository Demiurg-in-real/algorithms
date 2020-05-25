#ifndef __KRUSKAL__
#define __KRUSKAL__
#include <vector>
#include <utility>
#include <iostream>
class kruskal{
	private:
		int parthoar(std::vector<std::vector<int>>& kek, int low, int high);
		void qsort(std::vector<std::vector<int>>& kek, int low, int high);
		std::vector<std::vector<int>> versh;
		std::vector<std::vector<int>> tree;
		std::vector<std::vector<std::vector<int>>> gr;
	public:
		void krask();
		void make(std::vector<std::vector<std::vector<int>>> vect);
		std::vector<std::vector<int>> get(){
			return tree;
		}
};
#include "krusk.tpp"
#endif
