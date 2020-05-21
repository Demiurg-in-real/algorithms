void cicle::dfs(std::vector<int>& cicl, int pos, bool& end){
	cicl.push_back(pos); 
	gr[pos].first = true;
	for(size_t i = 0; i<gr[pos].second.size() && !end; i++){
		if(gr[pos].second[i] == cicl[0] && gr[gr[pos].second[i]].first) {
			end = true;
			cicl.push_back(gr[pos].second[i]);
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
			break;
		}
		if(!gr[gr[pos].second[i]].first){
			for(auto l = gr[gr[pos].second[i]].second.begin(); l<gr[gr[pos].second[i]].second.end(); l++)
				if( *l == pos){
					gr[gr[pos].second[i]].second.erase(l);
					break;
				}
			dfs(cicl, gr[pos].second[i], end);
			for(auto k = gr[pos].second.begin(); k<gr[pos].second.end(); k++)
				if( *k == gr[pos].second[i]){
					gr[pos].second.erase(k);
					break;
				}
		}
	}
}
void cicle::cic(){
	bool end = false;
	std::vector<int> help(0);
	dfs(eiler, 0, end);
	for(size_t i = 1; i< eiler.size()-1; i++){
		end = false;
		if( gr[eiler[i]].second.size() != 0){
			for(auto q = gr.begin(); q < gr.end(); q++) q->first = false;
			dfs(help, eiler[i], end);
		}
		else continue;
		for(size_t k = 0; k<eiler.size(); k++)
			if(eiler[k] == help[0]){
				for(size_t j = 1; j< help.size(); j++)
					eiler.insert(eiler.begin()+k, help[j]);
				break;
			}
		help.resize(0);
	}
}
