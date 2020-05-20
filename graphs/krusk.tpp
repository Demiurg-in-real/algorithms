void kruskal::make(std::vector<std::vector<std::vector<int>>> vect, bool bd){
	bedirected = bd;
	bool check = false;
	for(auto i = 0; i<vect.size(); i++){
		if(vect[i].size() != vect.size()) 
			check = true;
		for(int i = 0; i<gr.size(); i++)
			for(auto j = vect[i].begin(); j<vect[i].end(); j++)
				gr[i].second.push_back(*j);
	}
	versh.resize(0);
	for(int i = 0; i<gr.size(); i++){
		for(int j =0; j<gr[i].second.size(); j++){
			versh.resize(versh.size()+1);
			versh[versh.size() - 1].resize(4);
			versh[versh.size() - 1][0] = 0;
			versh[versh.size() - 1][1] = i;
			versh[versh.size() - 1][2] = gr[i].second[j][0];
			versh[versh.size() - 1][3] = gr[i].second[j][1];
			if(bedirected){
				for(auto l = gr[gr[i].second[j][0]].second.begin(); l< gr[gr[i].second[j][0]].second.end(); l++){
					if((*l)[0] == i){
						gr[gr[i].second[j][0]].second.erase(l);
						break;
					}
				}
			}
		}
	}
	qsort(versh, 0, versh.size()-1);
}
int kruskal::parthoar(std::vector<std::vector<int>>& kek, int low, int high){
	int pivot = kek[(low+high)/2][3];
	int i = low-1;
	int j = high+1;
	while(true){
		do{
			i += 1;
		}
		while(kek[i][3] < pivot);
		do{
			j -= 1;
		}
		while(kek[j][3] > pivot);
		if(i >= j)
			return j;
		std::swap(kek[i], kek[j]);
	}
}
void kruskal::qsort(std::vector<std::vector<int>>& kek, int low, int high){
	if (low<high){
		int p = parthoar(kek, low, high);
		qsort(kek, low, p-1);
		qsort(kek, p+1, high);
	}
}
void kruskal::krask(){
	int num = 1;
	versh[0][0] = num;
	bool neutral;
	for(int q = 1; q<versh.size(); q++){
		neutral = false;
		for(size_t w = 0; w<q; w++){
			if(versh[w][0] != (-1) && (versh[w][1] == versh[q][1] || versh[w][2] == versh[q][1])){
				int pos = (versh[w][1] == versh[q][1])?(2):(1);
				for(size_t e = 0; e<q; e++){
					if(versh[e][0] != (-1) && (versh[w][1] == versh[q][pos] || versh[w][2] == versh[q][pos])){
						if(versh[w][0] == versh[e][0]){
							versh[q][0] = (-1);
							break;
						}
						if(versh[w][0] != versh[e][0]){
							int tree1 = (versh[w][0] > versh[e][0])?(versh[w][0]):(versh[e][0]);
							int tree2 = (tree1 == versh[w][0])?(versh[e][0]):(versh[w][0]);
							for(size_t r = 0; r<q; r++)
								if(versh[r][0] == tree2)
									versh[r][0] = tree1;
							versh[q][0] = tree1;
							num--;
							break;
						}
					}
				}
			}
			if( w == (q-1))
				neutral = true;
		}
		if(neutral){
			num++;
			versh[q][0] = num;
		}
	}
	for(auto i = versh.begin(); i<versh.end(); i++)
		if( (*i)[0] == (-1))
			versh.erase(i);
}
