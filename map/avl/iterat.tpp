template<class K, class V, typename M/*, typename T*/> 
iterat<K,V,M>::iterat(const M* ch, int i):che(ch),pos(i){
}

template<class K, class V, typename M/*, typename T*/> 
iterat<K,V>& iterat<K,V,M>::operator=(const iterat<K,V>& it){
	this->pos = it.pos;
	this->siz=1;
	this->r.resize(this->siz);
	std::stack<M*> kek;
	M* lol = it.che;
	if(lol == nullptr) this->r[0] = lol;
	while(!(kek.empty) || lol != nullptr){
		if(lol != nullptr){
			kek.push(lol);
			lol = lol->left;
		}
		else{
			lol = kek.front();
			kek.pop();
			this->r.push_back(lol);
			this->siz++;
			this->r.resize(siz);
			lol = lol.right;
		}
	}
	if(pos == 1) this->pos = this->siz - 1;
	else this->pos = 0;
	return *this;
}

template<class K, class V, typename M/*, typename T*/> 
iterat<K,V>& iterat<K,V,M>::operator++(iterat<K,V>& i){
	if(i.pos < i.siz) i.pos=i.pos+1;
	return i;
}

template<class K, class V, typename M/*, typename T*/> 
iterat<K,V>& iterat<K,V,M>::operator--(iterat<K,V>& i){
	if(i.pos>0) i.pos = i.pos - 1;
	return i;
}

template<class K, class V, typename M/*, typename T*/> 
V& iterat<K,V,M>::operator*(){
	return r[pos]->value;
}
