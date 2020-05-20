#ifndef __PRIM__
#define __PRIM__
#include <vector>
#include <utility>
class Prim{
	private:
		std::vector<std::vector<std::vector<int>>> gr;
		std::vector<std::pair<int,std::vector<std::pair<int,int>>>> ngr;
		std::vector<std::vector<std::pair<int,int>>> vect;
		bool check(int size, int mean);
		void make(){
			for( auto i = ngr.begin(); i<ngr.end(); i++)
				for(auto j = i->second.begin(); j<i->second.end(); j++)
					vect[i->first].push_back(std::make_pair(j->first,j->second));
		}
	public:
		std::vector<std::vector<std::pair<int,int>>> get(){
			return vect;
		}
		void take(std::vector<std::vector<std::vector<int>>> gra){
			gr = gra;
			ngr.resize(gr.size());
		}
		void prim();
};
#include "prim.tpp"
#endif
