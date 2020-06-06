bm::bm(){
	stop.resize(0);
	for(size_t i = 0; i<2; i++){
		char j = (i == 0)?(0x41):(0x61);
		size_t k = 0;
		for(j,k; k<26; k++,j++)
			stop.push_back(std::make_pair(j,-1));
	}
}
void bm::make_suf_stop(const std::string& ustr){
	bool fir = false;
	suf.push_back(std::make_pair("",1));//hz
	for(int i = ustr.size()-1, j=1; i>=1; i--,j++){
		if(i!=(ustr.size()-1) && (ustr.substr(i,j).size()<(suf.end()-1)->second || (i+1)<=(ustr.size()/2)))
			fir = true;
		else
			fir = false;
		suf.push_back(std::make_pair(ustr.substr(i,j), (ustr.rfind(ustr.substr(i,j),i-1) != std::string::npos)?(ustr.size()-ustr.rfind(ustr.substr(i,j),i-1)-ustr.substr(i,j).size()):((fir)?((suf.end()-1)->second):(ustr.size()))));
	}
	suf.push_back(std::make_pair(ustr, (fir)?((suf.end()-1)->second):(ustr.size())));
	for(size_t i = 0; i<stop.size(); i++){
		stop[i].second = (stop[(i<26)?(i+26):(i-26)].second != (-1))?(stop[(i<26)?(i+26):(i-26)].second):( (ustr.rfind(stop[i].first,ustr.size()-2) != std::string::npos)?(ustr.rfind(stop[i].first,ustr.size()-2)):(-1));
		if(stop[(i<26)?(i+26):(i-26)].second == (-1))
			stop[(i<26)?(i+26):(i-26)].second = stop[i].second;
	}
}
void bm::clear(){
	for(size_t i = 0; i<stop.size(); i++)
		stop[i].second = -1;
	suf.resize(0);
}
void bm::search(const std::string& main, const std::string& submain, std::vector<int>& positions){
	positions.resize(0);
	make_suf_stop(submain);
	int i;
	size_t st,sf;
	for(pos = 0; pos<(main.size()-submain.size()+1);){
		for(i = submain.size()-1; i>=0 && submain[i] == main[pos+i];i--);
		if(i == (-1)){
			positions.push_back(pos);
			st = 1;
		}
		else{
			for(std::vector<std::pair<char,int>>::iterator k = stop.begin(); k<stop.end(); k++){
				if(k->first == main[pos+i]){
					st = i - k->second;
					break;
				}
			}
		}
		sf = suf[submain.size()-(i+1)].second;
		pos+=(sf > st)?(sf):(st);
	}
	clear();
}

