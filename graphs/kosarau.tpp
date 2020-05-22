void kosa::dfs(size_t pos){
	gr[pos].first = true;
	for(size_t i = 0; i<gr[pos].second.size(); i++)
		if(!gr[gr[pos].second[i]].first)
			dfs(gr[pos].second[i]);
	que.push(pos);
}
void kosa::invert(){
	for(size_t i =0; i<gr.size(); i++)
		for(size_t j =0; j<gr[i].second.size(); j++)
			ngr[gr[i].second[j]].second.push_back(i);
}
void kosa::dfs1(size_t pos){
	ngr[pos].first = true;
	way.push_back(pos);
	for(size_t i = 0; i<ngr[pos].second.size(); i++)
		if(!ngr[ngr[pos].second[i]].first)
			dfs1(ngr[pos].second[i]);
}
void kosa::kesa(){
	for(size_t i = 0; i<gr.size(); i++)
		if(!gr[i].first)dfs(i);
	std::vector<int> spis(0);
	while(!que.empty()){
		spis.push_back(que.front());
		que.pop();
	}
	for(auto i = spis.end(); i>= spis.begin(); i--){
		if(!ngr[*i].first){
			dfs1(*i);
			sv_spis.push_back(way);
			way.resize(0);
		}
	}
}
