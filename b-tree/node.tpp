template<typename K, typename V, typename S> node<K,V,S>::node(short step, K k, V v){
	this->t = step;
	leaf = true;
	items.resize(2*t-1);
	items[0] = new S(k,v);
	this->size++;
	child.resize(2*t);
}
template<typename K, typename V, typename S> node<K,V,S>::node(short step){
	this->t = step;
	this->leaf = true;
	this->size = 0;
	this->items.resize(2*step-1);
	this->child.resize(2*step);
}
template<typename K, typename V, typename S> short node<K,V,S>::siz(){
	return this->size;
}
template<typename K, typename V, typename S> node<K,V,S>::node(node<K,V,S>& ob){
	this->t = ob.t;
	this->size = ob.size;
	this->items.resize(2*(this->t)-1);
	this->child.resize(2*(this->t));
	for(unsigned short i=0;i<ob.size;i++){
		if(ob.items[i]!=nullptr) this->items[i] = new S(*(ob.items[i]));
		if(ob.child[i]!=nullptr) this->child[i] = new node<K,V,S>(*(ob.child[i]));
	}
	if(ob.child[ob.size] != nullptr) this->child[this->size] = new S(*(ob.child[ob.size]));
}
		
template<typename K, typename V, typename S> bool node<K,V,S>::full(){
	return (size == (2*t-1))? true:false;
}	
//template<typename K,typename V, typename S> bool node<K,V,S>::ch(){
//	for(short i = 0; i<size; i++) if(items[i] != nullptr) return true;//дурость, но надо обдумать, как цикл убрать
//	return false;
//}
