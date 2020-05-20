void kosa::dfs(size_t pos){
	static int time = 0;
	gr[pos].first = true;
	for(size_t i = 0; i<gr[pos].second.size(); i++){
		if(!gr[gr[pos].second[i]].first){
			time++;
			dfs1(gr[pos].second[i]);
		}
	}
	time++;
	timing[pos] = time;
}
void kosa::invert(){
	for(size_t i =0; i<gr.size(); i++)
		for(size_t j =0; j<gr[i].second.size(); j++)
			ngr[gr[i].second[j]].second.push_back(i);
}
void kosa::dfs1(size_t pos){
	gr[pos].first = true;
	way.push_back(pos);
	for(size_t i = 0; i<gr[pos].second.size(); i++){
		if(!gr[gr[pos].second[i]].first){
			dfs1(gr[pos].second[i]);
		}
	}
}
void kosa::kesa(){
	std::vector<int> time(gr.size());
	dfs(0);
	size_t n = 0;
	std::vector<int> spis(gr.size());
	for(size_t i =0; i<gr.size(); i++){
		n = 0;
		for(size_t j =0; j<time.size(); j++){
			n = (time[n] < time[j] && time[n] != (-1))?(n):(j);
		}
		spis.push_back(n);
		time[n] = -1;
	}
	for(int i = 0; i<gr.size(); i++) gr[i].first = true;
	for(auto i = spis.end(); i>= spis.begin(); i--){
		if(!gr[*i].first) dfs1(*i);
		sv_spis.push_back(way);
		way.resize(0);
	}
}
