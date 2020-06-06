void rabin_kramp(const std::string& str, const std::string& substr, std::vector<int>& pos){
	pos.resize(0);
	std::string subs = str;
	for(std::string::iterator kuku = subs.begin(); kuku<subs.end(); kuku++)
		for(std::string::iterator kuku1 = kuku+1; kuku1<subs.end();kuku1++)
			if(*kuku == *kuku1){
				subs.erase(kuku1);
				kuku1--;
			}
	size_t n = str.size();
	size_t m = substr.size();
	size_t d = subs.size();
	size_t d_m = (static_cast<int>(std::pow(d,m-1)))%29;
	size_t h = 0, h1 = 0;
	for(size_t i = 0; i<m-1;i++){
		h = d*h+(static_cast<int>(substr[i]));
		h1 = d*h1+(static_cast<int>(str[i]));
	}
	h%=29;
	h1%=29;
	for(size_t i =0; i<(n-m); i++){
		if(h == h1){
			if(i == 0 && substr == str.substr(i,m))
				pos.push_back(i);
			if(substr == str.substr(i+1,m))
				pos.push_back(i+1);
		}
		if(i < (n-m))
			h1 = ((d*(h1 - (d_m*static_cast<size_t>(str[i]))))+str[i+m])%29;
	}
}
void KMP(const std::string& str, const std::string& substr, std::vector<int>& pos){
	std::vector<int> pos1;
	prefix(substr,pos1);
	size_t red = 0;
	for(size_t i = 0; i<str.size(); i++){
		for(red; red>0 && (substr[red] != str[i]); red = pos1[red-1]);
		if(substr[red] == str[i])
			red++;
		if(red == substr.size()){
			pos.push_back(i-red+1);
			red = pos1[red-1];
		}
	}
}
