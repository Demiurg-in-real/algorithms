bool Prim::check_bd(std::vector<std::vector<std::vector<int>>>& vect){
	bool bedirected = true;
	for(size_t i = 0; i<vect.size(); i++){
		for(size_t j = 0; j<vect[i].size(); j++){
			for(size_t k = 0; k<vect[vect[i][j][0]].size(); k++){
				if( i == vect[vect[i][j][0]][k][0])
					break;
				if( k == (vect[vect[i][j][0]].size() - 1) )
					bedirected = false;
			}
			if(!bedirected)
				break;
		}
		if(!bedirected)
			break;
	}
	if(!bedirected){
		std::cout<<"Invalid graph. Breaking...\n";
		return false;
	}
	return true;
}
void Prim::make(std::vector<std::vector<int>> vect){
	bool matrix = true;
	for(size_t i =0; i<vect.size(); i++){
		if(vect[i].size() != vect.size()){
			matrix = false;
			break;
		}
	}
	gr.resize(vect.size());
	if(matrix){
		for(size_t i = 0; i<vect.size(); i++){
			for(size_t j = 0; j<vect[j].size(); j++){
				if( 0 < vect[i][j] && vect[i][j] < _PRIM__INF_){
					gr[i].resize(gr[i].size()+1);
					gr[i][gr.size()-1].resize(2);
					gr[i][gr.size()-1][0] = j;
					gr[i][gr.size()-1][1] = vect[i][j];
				}
			}
		}
	}
	else{
		std::cout<<"Some troubles with your matrix."<<std::endl<<"Exiting..."<<std::endl;
		exit(-1);
	}
	if(!check_bd(gr))
		exit(-1);
	result.resize(0);
}
void Prim::make(std::vector<std::vector<std::vector<int>>> vect){
	gr = vect;
	if(!check_bd(gr))
		exit(-1);
	result.resize(0);
}
void Prim::prim(){
	std::vector<int> id(gr.size());
	for(size_t i = 0; i<id.size(); i++)
		id[i] = i;
	size_t q,w,e;
	std::pair<int,int> low(0,0);
	for(q = 1; q<id.size();q++){
		low.first = 0;
		low.second = 0;
		for(w = 0; w<id.size(); w++){
			if(id[w] == 0){
				for(e = 0; e<gr[w].size(); e++){
					if(gr[low.first][low.second][1] > gr[w][e][1] && id[gr[w][e][0]] != 0){
						low.first = w;
						low.second = e;
					}
				}
			}
		}
		result.push_back(std::make_pair(low.first,gr[low.first][low.second][0]));
		id[gr[low.first][low.second][0]] = 0;
	}
}
