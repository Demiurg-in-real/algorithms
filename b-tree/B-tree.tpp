template<typename T, typename V, typename S> btree<T,V,S>::btree(unsigned short tm, T k, V v){
	t = tm;
	root = new S(t,k,v);
}

template<typename T, typename V, typename S> bool btree<T,V,S>::is_empty(){
	if(root == nullptr) return true;
	if(root->items[0] == nullptr) return true;
	return false;
}

template<typename T, typename V, typename S> btree<T,V,S>::btree(const S& ob){
	this->t = ob.t;
	this->root = new S(ob);
}

template<typename T, typename V, typename S>btree<T,V,S>& btree<T,V,S>::operator=(const btree<T,V,S>& ne){
	clear(root);
	this->t = ne.t;
	if(ne.root != nullptr) this->root = new S(*(ne.root));
	else this->root = nullptr;
	return *this;
}

template<typename T, typename V, typename S>V& btree<T,V,S>::operator[](T k){
	S* r1;
	S* r2;
	int i1;
	int i2;
	cout<<"wat1"<<endl;
	if(search(root,k,r1,r2,i1,i2)) return r2->items[i2]->value;
	cout<<"break"<<endl;
}

template<typename T, typename V, typename S> btree<T,V,S>::~btree(){
	clear(root);
}

template<typename T, typename V, typename S> void btree<T,V,S>::clear_all(){
	clear(root);
}

template<typename T, typename V, typename S> void btree<T,V,S>::clear(S* nod){
	for(unsigned short i = 0; i <= nod->size; i++) if(nod->child[i]!=nullptr) clear(nod->child[i]);
	delete nod;
}

template<typename T, typename V, typename S>bool btree<T,V,S>::search(S* nod, T k, S* prelast, S* last, int& pos1,int& pos2){//вроде ок
	if(nod == nullptr) return false;
	register short i;
	for(i=nod->size; i>0 && k<=nod->items[i-1]->key;i--){
		if(k == nod->items[i-1]->key) {
			last = nod;
			pos2=i-1;
			return true;//*(nod->keys.data()+(i-1))
		}
	}
	prelast = nod;
	pos1=i;
	return search(nod->child[i], k,prelast,last,pos1,pos2);
}

template <typename T, typename V, typename S> void btree<T,V,S>::merge(S* now, S* upper, int& pos1){//вроде ок
	short i, y;
	now->items[now->size]=upper->items[pos1];
	for(i = now->size + 1, y=0; y < (upper->child[pos1+1]->size); y++,i++) {
		now->items[i] = upper->child[pos1 + 1]->items[y];
		now->child[i] = upper->child[pos1 + 1]->child[y];
	}
	now->size+=(1+upper->child[pos1 + 1]->size);
	now->child[now->size] = upper->child[pos1 + 1]->child[upper->child[pos1+1]->size];
	delete upper->child[pos1+1];
	for(i= (pos1); i < upper->size - 1; i++){
		upper->items[i] = upper->items[i+1];
		upper->child[i+1] = upper->child[i+2];
	}
	upper->items[upper->size-1] = nullptr;
	upper->child[upper->size] = nullptr;
	upper->size--;
}

template <typename T, typename V, typename S> void btree<T,V,S>::traversal_right(S* prelast, S* last, int& pos1){//OK
	short i;
	last->items[last->size] = prelast->items[pos1];
	last->child[last->size+1] = prelast->child[pos1+1]->child[0];
	last->size++;
	prelast->items[pos1] = prelast->child[pos1 + 1]->items[0];
	for(i = 0; i < (prelast->child[pos1 +1]->size-1); i++) {
		prelast->child[pos1+1]->items[i] = prelast->child[pos1 + 1]->items[i+1];
		prelast->child[pos1+1]->child[i] = prelast->child[pos1 + 1]->child[i+1];
	}
	prelast->child[pos1 + 1]->child[prelast->child[pos1 + 1]->size-1] = prelast->child[pos1+1]->child[prelast->child[pos1+1]->size];//prelast->child[pos1+1]->size];
	prelast->child[pos1 + 1]->child[prelast->child[pos1 + 1]->size] = nullptr;
	prelast->child[pos1 + 1]->items[prelast->child[pos1 + 1]->size-1] = nullptr;
	prelast->child[pos1 + 1]->size--;
}

template <typename T, typename V, typename S> void btree<T,V,S>::traversal_left(S* prelast, S* last, int& pos1){//OK
	for(short i = last->size; i>0; i--) {
		last->items[i] = last->items[i-1];
		last->child[i+1] = last->child[i];
	}
	last->child[1] = last->child[0];
	last->child[0] = prelast->child[pos1 - 1]->child[prelast->child[pos1-1]->size];
	prelast->child[pos1 - 1]->child[prelast->child[pos1-1]->size] = nullptr;
	last->items[0] = prelast->items[pos1 - 1];
	prelast->items[pos1-1] = prelast->child[pos1-1]->items[prelast->child[pos1 - 1]->size - 1];
	prelast->child[pos1-1]->items[prelast->child[pos1 - 1]->size - 1] = nullptr;
	prelast->child[pos1 - 1]->size--;
	last->size++;
}

template <typename T, typename V, typename S> void btree<T,V,S>::uniq(S* prelast, S* last, int& pos1, int& pos2){//OK
	short i;
	int tim = pos1 - 1;
	if(pos1 == prelast->size){
		if(prelast->child[pos1-1]->size > t-1){
			traversal_left(prelast,last,pos1);
		}
		else merge(prelast->child[pos1 - 1], prelast, tim);
	}
	else{
		if(pos1 == 0){
			if(prelast->child[pos1+1]->size > t-1){
				traversal_right(prelast, last, pos1);		
			}
			else merge(last, prelast,pos1);
		}
		else{
			if(prelast->child[pos1+1]->size > t-1){
				traversal_right(prelast, last, pos1);
			}
			else{
				if(prelast->child[pos1-1]->size > t-1){
					traversal_left(prelast, last, pos1);
				}
				else merge(last, prelast, pos1);
			}
		}
	}
}

template<typename T, typename V, typename S>container<T,V>& btree<T,V,S>::nearer(bool where, S* from){
	S* res = from;
	short pos;
	if(where){
		while(res->child[res->size] != nullptr) res = res->child[res->size];
		pos=res->size-1;
	}
	else{
		while(res->child[0] != nullptr) res = res->child[0];
		pos = 0;
	}
	return *(res->items[pos]);
}

template<typename T, typename V, typename S>bool btree<T,V,S>::delete_item(S* r,T k){//вроде ок
	S* l=nullptr;
	S* pl=nullptr;
	int p1=0;
	int p2=0;
	if(search(r, k,pl,l,p1,p2)) return false;
	else{
		if(l->leaf) {
			delete l->items[p2];
			l->size--;
			for(short i = p2; i<l->size-1; i++) l->items[i] = l->items[i+1];//может быть косяк
			l->items[l->size - 1] = nullptr;
			l->size--;
			if(l->size <= t-1) uniq(pl,l,p1,p2);
		}
		else{
			container<T,V>* reserv;
			if(l->child[p2]->size > t-1){
				reserv = new container<T,V>(nearer(true,l->child[p1]));
				delete l->items[p2];
				l->items[p2] = reserv;
				delete_item(l->child[p2], reserv->key);
			}
			else{
				if(l->child[p2+1]->size > t-1){
					reserv = new container<T,V>(nearer(false, l->child[p1+1]));
					delete l->items[p2];
					l->items[p2] = reserv;
					delete_item(l->child[p2+1], reserv->key);
				}
				else{
					merge(l->child[p1], l->child[p1 + 1], p1);
					delete_item(l, k);
					if(pl == root && pl->size == 0){
						delete root;
						root = pl;
					}
				}
			}
		}
	}
}

template<typename T, typename V, typename S>void btree<T,V,S>::split(S* f, S* nf, short p){//OK
	S* res1 = new S(t);
	S* res2 = new S(t);
	unsigned short i;
	for(i=0; i<(t-1); i++){
		res1->items[i] = f->items[i];
		res2->items[i] = f->items[i+t];
		res1->child[i] = f->child[i];
		res2->child[i] = f->child[i+t];
		res1->size++;
		res2->size++;
	}
	res1->child[t-1] = f->child[t-1];
	res2->child[t-1] = f->child[2*t-1];
	res1->leaf = f->leaf;
	res2->leaf = f->leaf;
	for(i=nf->size; i>p; i--) {
		nf->items[i]=nf->items[i-1];
		nf->child[i+1]=nf->child[i];
	}
	nf->items[p] = f->items[t-1];
	nf->size++;
	delete f;//???????????
	nf->child[p] = res1;
	nf->child[p+1] = res2;
}
template<typename T,typename V, typename S> void btree<T,V,S>::addINF(S* nod, T k, V v){//OK
	if(nod == nullptr) nod = new S(t,k,v);
	else{
		short i;
		if(nod->leaf){
			for(i=nod->size; i>=1 && k<nod->items[i-1]->key; i--) nod->items[i] = nod->items[i-1];//проверь потом//вроде ок
			nod->items[i] = new container<T,V>(k,v);
			nod->size++;
		}
		else{
			for(i = nod->size; i>=1 && k<nod->items[i-1]->key;i--);//тут может быть косяк//вроде пофиксил
			//может добавить обработку совпадающих ключей...?
//			i++;
			if(nod->child[i]!= nullptr){
				if(nod->child[i]->full()){
					split(nod->child[i],nod, i);
					if(k>nod->items[i]->key) i++;
				}
			}
			addINF(nod->child[i],k, v);
		}
	}
}
template<typename T, typename V, typename S> void btree<T,V,S>::add(T k, V v){//ok
	if(root == nullptr) root = new S(t);
	if (root->full()){
cout<<"entered"<<endl;
		S* r = root;
		S* neW = new S(t);
		root = neW;
		root->leaf = false;
		root->child[0] = r;
		split(root->child[0],root, 0);
		addINF(root, k,v);
	}
	else{
cout<<"done"<<endl;
		addINF(root, k, v);
	}
}
