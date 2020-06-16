template<class K, class V, typename M> 
tree<K,V,M>::tree(K key, V value){
	root = new M(key, value);
}
template<class K, class V, typename M> 
tree<K,V,M>::tree(){
	root = new M(K(), V());
	clear_all();
}
template<class K, class V, typename M> 
tree<K,V>& tree<K,V,M>::operator=(const tree<K,V>& rete){ 
	clear_all();
	this->root = cop_tree(rete.root);
	return *this;
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
void tree<K,V,M>::print(){
	if(!(is_empty())) printi(root,0);
	else std::cout<<"Tree is empty"<<std::endl;
}

template<class K, class V, typename M> 
V* tree<K,V,M>::operator[](K key){ 
	M* kr = search(root,key);
	if(kr != nullptr) return &(kr->value);
	else nullptr;
//	exit(-1);
}

template<class K, class V, typename M> 
tree<K,V,M>::tree(const tree<K,V> &sec){
	this->root = cop_tree(sec.root);
}
template<class K, class V, typename M>
M* tree<K,V,M>::cop_tree(M* nod){
	if (nod == nullptr) return nullptr;
	M* newnod = new M(nod->key, nod->value);
	newnod->left = cop_tree(nod->left);
	newnod->right = cop_tree(nod->right);
	return newnod;
}

template<class K, class V, typename M> 
tree<K,V,M>::~tree(){
	clear_all();
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
bool tree<K,V,M>::check_rules(M* nod){
	int8_t balfac;
	std::stack<M*> kek;
	M* lvn = nullptr;
	while( (!kek.empty()) || nod != nullptr){
		if (nod != nullptr){
			kek.push(nod);
			nod = nod->left;
		}
		else{
			M* peknod = kek.top();
			if(peknod->right != nullptr && lvn != peknod->right){
				nod = peknod->right;
			}
			else{
				balfac = bf(peknod);
				if( (balfac>2 || balfac<(-2))) return true;
				lvn = kek.top();
				kek.pop();
			}
		}
	}
	return false;
}

template<class K, class V, typename M>
void tree<K,V,M>::clear_all(){
	std::stack<M*> kekov;
	M* lvn = nullptr;
	M* peknod = nullptr;
	while( (!kekov.empty()) || root != nullptr){
		if(root!=nullptr){
			kekov.push(root);
			root = root->left;
		}
		else{
			peknod = kekov.top();
			if(peknod->right != nullptr && lvn != peknod->right) root = peknod->right;
			else{
				delete peknod;
				lvn = kekov.top();
				kekov.pop();
			}
		}
	}
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
//	if(check_rules(root)) std::cout<<"Some troubles with tree\n";
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
