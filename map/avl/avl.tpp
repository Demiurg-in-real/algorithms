template<class K, class V, typename M> 
tree<K,V,M>::tree(K key, V value){
	root = new M(key, value);
}

template<class K, class V, typename M> 
tree<K,V>& tree<K,V,M>::operator=(const tree<K,V>& rete){ 
	return tree(rete);
}

template<class K, class V, typename M> 
int tree<K,V,M>::high(M* ob){
	return ob!=nullptr?ob->height:0;
}

template<class K, class V, typename M> 
void tree<K,V,M>::elevation(M* ob){ 
	ob->height =1 + (high(ob->left)>high(ob->right)?high(ob->left):high(ob->right));
}

template<class K, class V, typename M> 
int tree<K,V,M>::bf(M* ob){ 
	return high(ob->left) - high(ob->right);
}

template<class K, class V, typename M> 
bool tree<K,V,M>::is_empty(){
	return ((root == nullptr)?(true):(false));
}

template<class K, class V, typename M> 
M* tree<K,V,M>::finlef(M* ob){
	return(ob->left->left == nullptr)?(ob):(finlef(ob->left));
}

template<class K, class V, typename M> 
void tree<K,V,M>::print(){printi(root,0);
}

template<class K, class V, typename M> V tree<K,V,M>::operator[](K key){ 
	M* kr = search(root,key);
	if(kr != nullptr) return kr->value;
//	return NULL;
}

template<class K, class V, typename M> 
tree<K,V,M>::tree(const tree<K,V> &sec){
	std::queue<M*> que;
	this->root= new M(sec.root->key, sec.root->value);
	if(sec.root->left != nullptr)que.push(sec.root->left);
	if(sec.root->right != nullptr) que.push(sec.root->right);
	M* x;
	while(!que.empty()){
		x = que.front();
		this->root = insert(this->root,x->key,x->value);
		que.pop();
		if(x->left != nullptr) que.push(x->left);
		if(x->right != nullptr) que.push(x->right);
	}
}

template<class K, class V, typename M> 
tree<K,V,M>::~tree(){
	while(!is_empty()){
		root = delete_item (root, root->key);
	}
}

template <class K, class V, typename M> 
M* tree<K,V,M>::rotright(M* ob){
	M* swap = ob->left;
	ob->left = swap->right;
	swap->right = ob;
	elevation(swap->right);
	elevation(swap);
	return swap;
}

template <class K, class V, typename M> 
M* tree<K,V,M>::rotleft(M* ob){
	M* swap = ob->right;
	ob->right = swap->left;
	swap->left = ob;
	elevation(swap->left);
	elevation(swap);
	return swap;
}

template <class K, class V, typename M> 
M* tree<K,V,M>::search(M* ob, K key){
	if(ob == nullptr) return nullptr;
	if(ob->key == key) return ob;
	if(ob->key > key)return search(ob->left,key);
	if(ob->key < key)return search(ob->right,key);
}

template <class K, class V, typename M> 
M* tree<K,V,M>::balance(M* ob){
	elevation(ob);
	if(bf(ob) == 2){
		if(bf(ob->left) < 0) ob->left = rotleft(ob->left);
		return rotright(ob);
	}
	if(bf(ob) == -2){
		if(bf(ob->right) > 0)ob->right = rotright(ob->right);
		return rotleft(ob);
	}
	return ob;
}

template <class K, class V, typename M> 
M* tree<K,V,M>::insert(M* ob, K key, V value){
	if(ob==nullptr) return new M(key, value);
	if(key>ob->key)	ob->right = insert(ob->right,key,value);
	if(key<ob->key)	ob->left = insert(ob->left,key,value);
	if(ob->key == key) ob->value = value;
	return balance(ob);
}

template <class K, class V, typename M> 
M* tree<K,V,M>::delete_item(M* ob, K key){
	if(ob == nullptr) {
		df = true;
		return nullptr;
	}
	if(key>ob->key)ob->right = delete_item(ob->right, key);
	if(key<ob->key) ob->left = delete_item(ob->left,key);
	if(key == ob->key){
		if(ob->left == nullptr && ob->right == nullptr) {
			delete ob;
			return nullptr;
		}
		M* res;
		if(ob->right == nullptr)res = ob->left;
		else{
			if(ob->right->left == nullptr){
				res = ob->right;
				res->left=ob->left;
			}
			else{
				M* rese = finlef(ob->right);
				res = new M(rese->left->key,rese->left->value);
				res->left = ob->left;
				res->right = delete_item(ob->right, res->key);
			}
		}
		delete ob;
		return balance(res);
	}
	return balance(ob);
}

template<class K, class V, typename M>
void tree<K,V,M>::printi(M *treee, int level){      
    if (treee->right) printi(treee->right, level + 1);
    for (int i = 0; i < level; i++) std::cout << "-";
    std::cout << treee->key << "_" << treee->value << std::endl;
    if (treee->left) printi(treee->left, level + 1);
}

template <class K, class V, typename M> 
void tree<K,V,M>::insert(K key, V value){
	root = insert(root, key,value);
}

template <class K, class V, typename M> 
void tree<K,V,M>::delete_item(K key){
	root = delete_item(root,key);
	if(df == true) {
		std::cerr<<"Can't find this object!"<<std::endl;
		df = false;
	}
	else std::cout<<"Success."<<std::endl;
}
