template<typename kek, typename rer> bool role<kek,rer>::empty(){ return mass.empty();}
template<typename kek, typename rer> uint64_t role<kek,rer>::siz(){ return mass.size();}
template<typename kek, typename rer> const kek& role<kek,rer>::max(){ if(mass.empty() != true) return mass.at(0);}
template<typename kek, typename rer> void role<kek,rer>::reset(unsigned long posit){
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
template<typename kek, typename rer> kek role<kek,rer>::erase(unsigned long posit){
	kek hek=mass[posit];
	mass[posit] = mass[mass.size()-1];
	reset(posit);
	mass.resize(mass.size()-1);
	return hek;
}
template<typename kek, typename rer> void role<kek,rer>::push(kek elem){
	mass.push_back(elem);
	kek swap;
	for(unsigned long position = (mass.size()-1), i=((position-1)/2); position!=0;position=i, i=((i-1)/2)){
		if(mass[i] < mass[position]){
			std::swap(mass[i], mass[position]);
		}
		else break;
	}
}
template<typename kek, typename rer> void role<kek,rer>::print(){
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
template<typename kek, typename rer> kek role<kek,rer>::pop(){ return erase(0);}
