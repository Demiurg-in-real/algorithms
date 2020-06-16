std::size_t prefix(std::string wat){
	std::size_t k;
	std::vector<size_t> pi(wat.size());
	pi[0] = k = 0;
	for(std::size_t i = 1; i<wat.size();i++){
		for(;k>0 && wat[i] != wat[k]; k = pi[k-1]);
		if(wat[i] == wat[k])
			k++;
		pi[i] = k;
	}
	return *(pi.end()-1);
}
void prefix(std::string wat,std::vector<int>& pi){
	size_t k;
	pi.clear();
	pi.resize(wat.size());
	pi[0] = k = 0;
	for(size_t i = 1; i<wat.size();i++){
		for(;k>0 && wat[i] != wat[k]; k = pi[k-1]);
		if(wat[i] == wat[k])
			k++;
		pi[i] = k;
	}
}

