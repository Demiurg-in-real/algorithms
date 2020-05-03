template<typename K, typename V, typename obj> 
int serie<K,V,obj>::search(K k){
	for(int i = 0; i<kek.size();i++) if(!kek[i].free && kek[i].key == k) return i;
	return -1;
}

template<typename K, typename V, typename obj> 
serie<K,V,obj>::serie(){
	size = 0; 
	empt=true;
};

template<typename K, typename V, typename obj> 
bool serie<K,V,obj>::empty(){ 
	return (size == 0)?true:false;
}

template<typename K, typename V, typename obj>
void serie<K,V,obj>::resiz(){
	kek.resize(kek.size()+1);
}

template<typename K, typename V, typename obj>
obj& serie<K,V,obj>::operator[](unsigned long long k){
	return kek.at(k);
}
