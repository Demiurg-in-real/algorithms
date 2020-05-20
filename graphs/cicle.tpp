void cicle::dfs(std::vector<int>& cicl, int pos, bool& end){
	cicl.push_back(pos); 
	gr[pos].first = true;
	for(size_t i = 0; i<gr[pos].second.size(); i++){
		if(end)
			break;
		if(gr[pos].second[i] == cicl[0] && gr[gr[pos].second[i]].first) {
			end = true;
			cicl.push_back(gr[pos].second[i]);
			break;
		}
		if(!gr[gr[pos].second[i]].first){
			for(auto l = gr[gr[pos].second[i]].second.begin(); l<gr[gr[pos].second[i]].second.end(); l++)
				if( *l == pos){
					gr[gr[pos].second[i]].second.erase(l);
					break;
				}
			for(auto k = gr[pos].second.begin(); k<gr[pos].second.end(); k++)
				if( *k == gr[pos].second[i]){
					gr[pos].second.erase(k);
					break;
				}
			dfs(cicl, gr[pos].second[i], end);

		}

	}
}
void cicle::del(std::vector<int>& cicl){
	for(auto i = cicl.begin(); i<cicl.end()-1; i++){
		for(auto j = gr[*(i+1)].second.begin(); j<gr[*(i+1)].second.end(); j++)
			if( *j == *i)
				gr[*(i+1)].second.erase(j);
		for(auto j = gr[*i].second.begin(); j < gr[*i].second.end(); j++)
			if( *j == *(i+1))
				gr[*i].second.erase(j);
	}
}
void cicle::cic(){
	bool end = false;
for(size_t c = 0; c<gr.size(); c++){
			std::cout<<std::endl;
			for(auto v : gr[c].second){
				std::cout<<v<<" ";
			}
		}
	std::vector<int> help(0);
	dfs(eiler, 0, end);
	for(auto i:eiler)std::cout<<i<<std::endl;
	std::cout<<"-------------------------------\n";
	del(eiler);
	for(size_t i = 0; i< gr.size(); i++){
		end = false;
		if( gr[i].second.size() != 0)dfs(help, i, end);
		else continue;
		std::cout<<"graph on "<<i<<std::endl;
		for(size_t c = 0; c<gr.size(); c++){
			std::cout<<std::endl;
			for(auto v : gr[c].second){
				std::cout<<v<<" ";
			}
		}				
		std::cout<<"\n-----print-----"<<std::endl;
		for(auto l:help) std::cout<<l<<std::endl;
		std::cout<<"---------------"<<std::endl;
		for(int j = 0; j<help.size()-1; j++){
			eiler.insert(eiler.begin()+i, help[j]);
		}
		help.resize(0);
		del(eiler);
	}
}
