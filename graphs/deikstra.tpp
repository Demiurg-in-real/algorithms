Deikstra::Deikstra(std::vector<std::vector<std::vector<int>>> graph){
	gr = graph;
	ways.resize(gr.size());
	for(auto i = ways.begin(); i<ways.end(); i++) i->second = (-1);
}
std::vector<int> Deikstra::get(){
	for(auto i = ways.begin(); i<ways.end(); i++)
		long_ways.push_back(i->second);
	return long_ways;
}
void Deikstra::dik(size_t now){
	ways[now].first = true;
	for(size_t i = 0; i<gr[now].size(); i++){
		if(!ways[gr[now][i][0]].first){
			if(ways[gr[now][i][0]].second > (ways[now].second + gr[now][i][1]) || ways[gr[now][i][0]].second != (-1)){
				ways[gr[now][i][0]].second = ways[now].second + gr[now][i][1];
			}
		}
	}
	size_t check, next;
	for(size_t i = 0; i<ways.size(); i++){
		if(!ways[i].first){
			next = i;
			check = ways[i].second;
			break;
		}
	}
	for(size_t i = 0; i<ways.size(); i++){
		if(!ways[i].first) {
			if(check > ways[i].second){
				check = ways[i].second;
				next = i;
			}
		}
	}
	dik(next);
}
