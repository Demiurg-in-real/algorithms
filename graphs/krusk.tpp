void kruskal::make(std::vector<std::vector<std::vector<int>>> vect){
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
		exit(0);
	}
	gr.resize(0);
	gr.resize(8);
	gr = vect;
	for(int i = 0; i<vect.size(); i++){
		for(int j =0; j<vect[i].size(); j++){
			versh.resize(versh.size()+1);
			versh[versh.size() - 1].resize(3);
			versh[versh.size() - 1][0] = i;
			versh[versh.size() - 1][1] = vect[i][j][0];
			versh[versh.size() - 1][2] = vect[i][j][1];
			if(bedirected){
				for(auto l = vect[gr[i][j][0]].begin(); l< vect[gr[i][j][0]].end(); l++){
					if((*l)[0] == i){
						vect[gr[i][j][0]].erase(l);
						break;
					}
				}
			}
		}
	}
	qsort(versh, 0, versh.size()-1);
}
int kruskal::parthoar(std::vector<std::vector<int>>& kek, int low, int high){
	int pivot = kek[(low+high)/2][2];
	int i = low-1;
	int j = high+1;
	while(true){
		do{
			i += 1;
		}
		while(kek[i][2] < pivot);
		do{
			j -= 1;
		}
		while(kek[j][2] > pivot);
		if(i >= j)
			return j;
		std::swap(kek[i], kek[j]);
	}
}
void kruskal::qsort(std::vector<std::vector<int>>& kek, int low, int high){
	if (low<high){
		int p = parthoar(kek, low, high);
		qsort(kek, low, p);
		qsort(kek, p+1, high);
	}
}
void kruskal::krask(){
	std::vector<int> id(gr.size());
	for(size_t i =0; i<id.size(); i++)
		id[i] = i;
	for(size_t i = 0; i<versh.size(); i++){
		int first = versh[i][0];
		int second = versh[i][1];
		int len = versh[i][2];
		if(id[first] != id[second]){
			tree.push_back(versh[i]);
			int n = id[first];
			int o = id[second];
			for(size_t j = 0; j<id.size(); j++)
				id[j] = (id[j] == o)?(n):(id[j]);
		}
	}
}
