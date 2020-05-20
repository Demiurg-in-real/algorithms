bool flori::bd(){
	for(size_t i = 0; i<gr.size(); i++){
		for(size_t j = 0; j<gr[i].second.size(); j++){
			for(size_t k =0; k<gr[gr[i].second[j]].second.size(); k++){
				if(gr[gr[i].second[j]].second[k] == i)
					break;
				if(k == (gr[gr[i].second[j]].second.size()-1))
					return false;
			}
		}
	}
	return true;
}
void flori::can_work(){
	ie = false;
	he = false;
	if(bd()){
		for(size_t i = 0 ; i<gr.size(); i++)
			if(((gr[i].second.size())%2) != 0)
				ie = true;
	}
	else{
		std::vector<std::vector<int>> lol;
		kosa kek(gra);
		kek.kesa();
		lol = kek.get(true);
		int one = 0;
		ie = true;
		for(size_t i = 0; i<lol.size(); i++){
			if(lol.size() > 1)
				one++;
			if(one == 2)
				ie = false;
		}
	}
	if(!ie && bd()){
		int two = 0;
		he = true;
		for(size_t i = 0; i<gr.size(); i++){
			if( ((gr[i].second.size())%3) == 0)
				two++;
			if(two == 3)
				he = false;
		}
	}
}
void flori::Flori(std::vector<int>& cicle){
	can_work();
	if(ie || he){}
	else{
		std::cout<<"Can't work. Not correct graph."<<std::endl;
		return;
	}
	int last = 0;
	int pos = 0;
	int next = gra[last][0];
	do{
		cicle.push_back(last);
		for(int i = 0; i<gra[last].size(); i++){
			pos = i;
			if(gra[gra[last][i]].size() > 1){
				next = gra[last][i];
				break;
			}
			else
				next = gra[last][i];
		}
		gra[last].erase(gra[last].begin()+pos);
		for(auto i = gra[next].begin(); i<gra[next].end(); i++){
			if( *i == last){
				gra[next].erase(i);
				elem--;
				break;
			}
		}
		last = next;
		elem-=1;
	}
	while( elem > 0 );
	cicle.push_back(last);
}
