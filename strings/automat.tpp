automat::automat(){
	graph.resize(0);
}
void automat::make_graph(std::string str){
	subs = str;
	std::string rss = str;
	graph.clear();
	graph.resize(subs.size()+1);
	for(std::string::iterator kuku = subs.begin(); kuku<subs.end(); kuku++)
		for(std::string::iterator kuku1 = kuku+1; kuku1<subs.end();kuku1++)
			if(*kuku == *kuku1){
				subs.erase(kuku1);
				kuku1--;
			}
	for(size_t i = 0; i<graph.size(); i++){
		graph[i].resize(subs.size());
		for(size_t j = 0; j<graph[i].size(); j++){
			graph[i][j].first = subs[j];
			if(i<rss.size() && graph[i][j].first == rss.at(i))
				graph[i][j].second = i+1;
			else
				graph[i][j].second = prefix((rss.substr(0,i)+graph[i][j].first));
		}
	}
}
void automat::search(const std::string& str, const std::string& substr, std::vector<int>& pos){
	make_graph(substr);
	int posit = 0;
	for(int i = 0; i<(str.size() - substr.size()+1);){
		for(int j = 0; j<graph[posit].size();j++){
			if( (i+posit) != str.size() && graph[posit][j].first == str.at(i+posit)){
				if(posit == (graph.size()-2))
					pos.push_back(i);
				if(graph[posit][j].second != (posit+1)){
					i+=(posit != 0)?(posit-graph[posit][j].second):(1);
					posit = graph[posit][j].second;
					break;
				}
				posit = graph[posit][j].second;
			}
			else
				if(j == (graph[posit].size()-1)){
					i+=(posit != 0)?(posit):(1);
					posit = 0;
				}
		}
	}
}
