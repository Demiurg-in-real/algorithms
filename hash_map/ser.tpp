template<typename K, typename V, typename obj> 
obj& serie<K,V,obj>::operator[](int i){
	return kek[i];
}

template<typename K, typename V, typename obj> 
serie<K,V,obj>::serie(){
	size = 0; 
	empt=true;
};

template<typename K, typename V, typename obj> 
bool serie<K,V,obj>::empty(){ 
	return empt;
}

template<typename K, typename V, typename obj> 
bool serie<K,V,obj>::insert(K k, V v){
	if(empt) empt=false;
	size++;
	for(short i=0; i<kek.size();i++) {
		if(kek[i].free) {
			kek[i].insert(k,v);
			return true;
		}
	}
	kek.resize(kek.size()+1);
	kek[kek.size()-1].insert(k,v);
	return true;
}

template<typename K, typename V, typename obj>
short serie<K,V,obj>::search(K k){
	for(short i=0; i<kek.size();i++) if(kek[i].key == k) return i;
	return -1;
}

template<typename K, typename V, typename obj>
bool serie<K,V,obj>::delet(K k){
	short i = search(k);
	if(i){
		kek[i].delet();
		size--;
		if(size == 0) empt = true;
		return true;
	}
	else return false;
}

template<typename K, typename V, typename obj>
const V& serie<K,V,obj>::get(K k){
	short i = search(k);
	if(i != (-1)) return kek[i].value;
	else return V();
}
