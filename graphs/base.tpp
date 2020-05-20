void Base::make(std::vector<std::vector<int>> vect){
	bool check = false;
	for(auto i = 0; i<vect.size(); i++)
		if(vect[i].size() != vect.size()) 
			check = true;
	if(check)
		for(int i = 0; i<gr.size(); i++)
			for(auto j = vect[i].begin(); j<vect[i].end(); j++)
				gr[i].second.push_back(*j);
	else
		for(int i = 0; i<gr.size(); i++)
			for(int j = 0; i<vect[i].size(); i++)
				if(vect[i][j] != (((unsigned int)(int())) - 1))
					gr[i].second.push_back(j);
}
Base::Base(std::vector<std::vector<int>> vect){
	gr.resize(vect.size());
	make(vect);
}
