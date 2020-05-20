void floid(std::vector<std::vector<int>>& gr){
	for(size_t k = 0; k<gr.size(); k++){
		for(size_t i = 0; i<gr.size(); i++){
			for(size_t j = 0; j<gr.size(); j++){
				gr[i][j] = (gr[i][j] < (gr[i][k] + gr[k][j])) ? (gr[i][j]) : (gr[i][k] + gr[k][j]);
			}
		}
	}
}
