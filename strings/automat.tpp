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
	for(size_t i = 0; i<graph.size(); i++)
		for(size_t j = 0; j<subs.size(); j++)
			graph[i].insert(subs[j],(i<rss.size() && subs[j] == rss.at(i))?(i+1):(prefix((rss.substr(0,i)+subs[j]))));
}

void automat::search(const std::string& str, const std::string& substr, std::vector<int>& pos){
	make_graph(substr);
	int* checker = nullptr;
	for(int i = 0; i<(str.size());i++){
		checker = graph[(checker)?(*checker):(0)][str[i]];
		if(checker != nullptr)
			if(*checker == (graph.size()-1))
				pos.push_back(i-substr.size()+1);
	}
}
