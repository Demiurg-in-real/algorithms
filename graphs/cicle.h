#ifndef __CICLE__
#define __CICLE__
#include "dfs.h"
#include<iostream>
class cicle:public DFS{
	private:
		std::vector<int> eiler;
	protected:
		void dfs(std::vector<int>& cicl, int pos, bool& end);
		void del(std::vector<int>& cicl);
	public:
		void cic();
		virtual std::vector<int> get(){
			return eiler;
		}
		cicle(std::vector<std::vector<int>> vec):DFS(vec){
			eiler.resize(0);
		}
		void dfs(size_t index){};
};
#include "cicle.tpp"
#endif
