#ifndef __KOSA__
#define __KOSA__
#include "dfs.h"
#include<iostream>
#include<queue>
class kosa:public DFS{
	private:
		std::vector<int> way;
		std::vector<std::vector<int>> sv_spis;
		std::vector<std::pair<bool, std::vector<int>>> ngr;
		std::queue<int> que;
		void invert();
	protected:
		void dfs(size_t pos);//,size_t& time);
		void dfs1(size_t pos);
	public:
		std::vector<std::vector<int>> get(bool kek){
			return sv_spis;
		}
		void kesa();
		kosa(std::vector<std::vector<int>> vec):DFS(vec){
			way.resize(0);
			sv_spis.resize(0);
			ngr.resize(vec.size());
			invert();
		}
};
#include "kosarau.tpp"
#endif
