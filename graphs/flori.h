#ifndef __FLORI__
#define __FLORI__
#include <iostream>
#include "base.h"
#include "kosarau.h"
class flori:public Base{
	private:
		bool ie;
		bool he;
		bool bd();
		void can_work();
		int elem;
		std::vector<std::vector<int>> gra;
	public:
		void Flori(std::vector<int>& cicl);
		flori(std::vector<std::vector<int>> grap):Base(grap){
			elem = 0;
			gra.resize(gr.size());
			for(size_t i = 0; i<gr.size(); i++){
				for(size_t j = 0; j<gr[i].second.size(); j++){
					gra[i].push_back(gr[i].second[j]);
					elem++;
				}
			}
		}
};
#include "flori.tpp"
#endif
