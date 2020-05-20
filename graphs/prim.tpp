bool Prim::check(int size, int mean){
	for(size_t q = 0; q < size; q++) 
		if(mean == ngr[q].first) 
			return true;
	return false;
}
void Prim::prim(){
	ngr.resize(gr.size());
	ngr[0].first = 0;
	int from,to;
	int way;
	int size = 1;
	for(size_t j = 1; j<ngr.size(); j++){
		for(size_t i =0; i < j; i++){
			for(size_t q = 0; q < gr[ngr[i].first].size(); q++){
				if(check(size, gr[ngr[i].first][q][0]))
					continue;
				way = gr[ngr[i].first][q][1];
				to = q;
				from = i;
				break;
			}
			for(size_t q = 0; q < gr[ngr[i].first].size(); q++){
				if(check(size, gr[ngr[i].first][q][0]))
					continue;
				if(gr[ngr[i].first][q][1] < way){
					from = i;
					to = q;
					way = gr[ngr[i].first][q][1];
				}
			}
		}
		ngr[from].second.push_back(std::pair<int,int>(to,way));
		ngr[j].first = to;
		size++;
	}
	make();
}
