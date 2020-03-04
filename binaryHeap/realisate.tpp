template<typename kek> bool role<kek>::empty(){ return mass.empty();}
template<typename kek> uint64_t role<kek>::siz(){ return mass.size();}
template<typename kek> kek role<kek>::max(){ if(mass.empty() == false) return mass.at(0);}
template<typename kek> void role<kek>::reset(unsigned long posit){
	unsigned long l = 2*posit+1;
	unsigned long r = 2*posit+2;
	unsigned long b = posit;
	kek swap;
	if( l < mass.size() && mass[l] > mass[b]) b = l;
	if( r < mass.size() && mass[r] > mass[b]) b = r;
	if( b != posit){
		std::swap(mass[posit], mass[b]);
		reset(b);
	}
}
template<typename kek> void role<kek>::erase(unsigned long posit){
	mass[posit] = mass[mass.size()-1];
	reset(posit);
	mass.resize(mass.size()-1);
}
template<typename kek> void role<kek>::push(kek elem){
	for(unsigned long i=0; i<mass.size();i++) if(mass.at(i) == elem) return;
	mass.push_back(elem);
	kek swap;
	for(unsigned long position = (mass.size()-1), i=((position-1)/2); position!=0;position=i, i=((i-1)/2)){
		if(mass[i] < mass[position]){
			std::swap(mass[i], mass[position]);
		}
		else break;
	}
}
template<typename kek> void role<kek>::print(){
	unsigned long level=0;
	cout<<std::endl<<std::endl;
	for(unsigned long i = 0; i<mass.size();i++){
		if(i == (pow(2,level)-1)){
			cout<<std::endl;
			level++;
		}
		printf("%i ", mass.at(i));
	}
	cout<<std::endl;
}
