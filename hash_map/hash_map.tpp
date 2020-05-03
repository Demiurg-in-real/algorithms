template<typename K, typename V, typename M, typename W> 
const size_t hash_map<K,V,M,W>::size(){
	return num_mem;
}

template<typename K, typename V, typename M, typename W> 
double& hash_map<K,V,M,W>::get_C(){
	return C;
}

template<typename K, typename V, typename M, typename W> 
const double hash_map<K,V,M,W>::real_C(){
	return (static_cast<double>(num_mem)/num_ser);
}

template<typename K, typename V, typename M, typename W> 
void hash_map<K,V,M,W>::delete_all(){
	kek.erase(kek.begin(), kek.end());
}

template<typename K, typename V, typename M, typename W> 
void hash_map<K,V,M,W>::hash(W& i, K k){
	double wat;
	wat = (num_ser*(std::modf(k*((std::sqrt(5.0) - 1)/2.0),&wat)));
	i = std::floor(wat);
}


template<typename K, typename V, typename M, typename W> 
void hash_map<K,V,M,W>::hash(W& i, std::string k){
	unsigned long long c = 0;
	for (unsigned int kuk = 0; kuk<k.size(); kuk++) c+=k[kuk];
	hash(i,c);
}

template<typename K, typename V, typename M, typename W> 
bool hash_map<K,V,M,W>::insert(K k, V v){
	W i = 0;
	hash(i,k);
	int hehe = kek[i].search(k);
	if (hehe != (-1)) kek[i][hehe].value = v;
	else{
		if (kek[i].empty()) kek[i].empt = false;
		bool check = true;
		int j;
		for(j = 0; j<kek[i].siz(); j++){
			if(kek[i][j].free){
				check = false;
				break;
			}
		}
		if(check){
			kek[i].resiz();
			j = kek[i].siz() - 1;
		}
		kek[i][j].free = false;
		kek[i][j].key = k;
		kek[i][j].value = v;
		kek[i].size++;
		num_mem++;
		if ( get_C() <= real_C() ) rehash((num_mem/2)+10);
	}
	return true;
}

template<typename K, typename V, typename M, typename W> 
V& hash_map<K,V,M,W>::operator[](K k){
	W i = 0;
	hash(i,k);
	int heh = kek[i].search(k);
	return (heh != (-1))?(kek[i][heh].value):V();
}

template<typename K, typename V, typename M, typename W> 
bool hash_map<K,V,M,W>::delet(K k){
	W i = 0;
	hash(i,k);
	int heh = kek[i].search(k);
	if(heh!=(-1)){
		kek[i][heh].free = true;
		kek[i].size--;
		this->num_mem--;
		return true;
	}
	else return false;
}

template<typename K, typename V, typename M, typename W> 
void hash_map<K,V,M,W>::rehash(int ns){
	std::vector<M> lol;
	lol = kek;
	kek.erase(kek.begin());
	kek.resize(ns);
	this->num_ser = ns;
	for(long i=0; i<lol.size();i++){
		if(!lol[i].empty()){
			for(int y=0; y<lol[i].siz();y++){
				if(!lol[i][y].free){
					insert(lol[i][y].key, lol[i][y].value);
				}
			}
		}
	}
}
template<typename K,typename V, typename M, typename W>
void hash_map<K,V,M,W>::print(){
	for(int i=0; i<num_ser;i++){
		if(!kek[i].empty()){
			for(int y = 0; y<kek[i].siz();y++){
				if(!kek[i][y].free){
					std::cout<<"В списке номер "<<i<<" находятся элементы"<<kek[i][y].key<<" - ключ,"<<kek[i][y].value<<" - значение под номером "<<y<<std::endl;
				}
			}
		}
	}
}

