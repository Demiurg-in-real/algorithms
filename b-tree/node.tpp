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
//template<typename K> void node<K>::cop(unsigned short from,unsigned short to, node* ob){
//	for(unsigned short i = from, unsigned short k=0; i<to;i++,k++){
//		this->keys[k]=ob->keys[i];
//		this->child[k]=ob->child[i];
//		this->size++;
//	}
//	if(from == 0) this->child[this->size] = ob->child[to];
//}
template<typename K, typename V, typename S> bool node<K,V,S>::full(){
	return (size == (2*t-1))? true:false;
}	
template<typename K> bool node<K>::ch(){
	for(short i = 0; i<size; i++) if(items[i] != nullptr) return true;//дурость, но надо обдумать, как цикл убрать
	return false;
}
