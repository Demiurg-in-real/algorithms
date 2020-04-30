template<typename T, typename V, typename S>bool btree<T,V,S>::search(S* nod, T k, S* prelast, S* last, int* pos1,int* pos2){
	short i;
	for(i=nod->size(); i>=0 && k<=nod->items[i-1]->key;i--){
		if(k == nod->items[i-1]->key) {
			last = nod;
			*pos2=i-1;
			return true;//*(nod->keys.data()+(i-1))
		}
	}
	prelast = nod;
	*pos1=i;
	return search(nod->child[i], k,prelast,last,pos1,pos2);
}

template <typename T, typename V, typename S> void btree<T,V,S>::merge(S* now, S* upper, int* pos1){
	now->items[now->size]=upper->items[*pos1];
	for(i = now->size + 1, y=0; y < (upper->child[*pos1 + 1]->size); y++ i++) {
		now->items[i] = upper->child[*pos1 + 1]->items[y];
		now->child[i] = upper->child[*pos1 + 1]->child[y];
	}
	now->size+=(1+upper->child[*pos1 + 1]->size);
	now->child[now->size] = upper->child[*pos1 + 1]->child[upper->child[*pos1+1]->size];
	delete upper->child[*pos1+1];
	for(i= (*pos1); i < upper->size - 1; i++){
		upper->items[i] = upper->items[i+1];
		upper->child[i+1] = upper->child[i+2];
	}
	upper->child[upper->size] = nullptr;
	upper->size--;
}

template <typename T, typename V, typename S> void btree<T,V,S>::traversal_right(S* prelast, S* last, int* pos1){
	short i;
//	for(i = *pos2; i < (last->size - 1); i++) {
//		last->items[i] = last->items[i+1];
//		last->child[i+1] = last->child[i+2];
//	}
//	last->child[last->size] = prelast->child[*pos1+1]->child[0];
	last->items[last->size] = prelast->items[*pos1];
	prelast->items[*pos1] = prelast->child[*pos1 + 1]->items[0];
	for(i = 0; i < (prelast->child[*pos1 +1]->size - 1); i++) {
		prelast->child[*pos1+1]->items[i] = prelast->child[*pos1 + 1]->items[i+1];
		prelast->child[*pos1+1]->child[i] = prelast->child[*pos1 + 1]->items[i+1];
	}
	prelast->child[*pos1 + 1]->child[prelast->child[*pos1 + 1]->size +1] = prelast->child[*pos1+1]->child[0];//prelast->child[*pos1+1]->size];
	prelast->child[*pos1 + 1]->child[prelast->child[*pos1 + 1]->size] = nullptr;
	prelast->child[*pos1 + 1]->items[prelast->child[*pos1 + 1]->size-1] = nullptr;
	prelast->child[*pos1 + 1]->size--;
}

template <typename T, typename V, typename S> void btree<T,V,S>::traversal_left(S* prelast, S* last, int* pos1){
	for(short i = last->size; i>0; i--) {
		last->items[i] = last->items[i-1];
		last->child[i+1] = last->child[i];
	}
	last->child[1] = last->child[0];
	last->child[0] = prelast->child[*pos1 - 1]->child[prelast->child[*pos1+1]->size];
	prelast->child[*pos1 - 1]->child[prelast->child[*pos1-1]->size] = nullptr;
	last->items[0] = prelast->items[*pos1 - 1];
	prelast->items[*pos1-1] = prelast->child[*pos1-1]->items[prelast->child[*pos1 - 1]->size - 1];
	prelast->child[*pos1-1]->items[prelast->child[*pos1 - 1]->size - 1] = nullptr;
	prelast->child[*pos1 - 1]->size--;
}

template <typename T, typename V, typename S> void btree<T,V,S>::uniq(S* prelast, S* last, int* pos1, int* pos2){
	short i;
	int tim = *pos1 - 1;
	if(*pos1 == prelast->size){
		if(prelast->child[*pos1-1]->size >= t){
			traversal_left(prelast,last,pos1);
		}
		else merge(prelast->child[*pos1 - 1], prelast, &tim/*(*pos-1)*/);
	}
	if(*pos1 == 0){
		if(prelast->child[*pos1+1]->size >= t){
			traversal_right(prelast, last, pos1);		
		}
		else merge(last, prelast,pos1);
	}
	else{
		if(prelast->child[*pos1+1]->size >= t){
			traversal_right(prelast, last, pos1,pos2);
		}
		else{
			if(prelast->child[*pos1-1]->size >= t){
				traversal_left(prelast, last, pos1, pos2);
			}
			else merge(last, prelast, pos1);
		}
	}
}

template<typename T, typename V, typename S>bool delete_item(S* r,K k){
	S* l=nullptr;
	S* pl=nullptr;
	int *p1=0;
	int *p2=0;
	search(r, k,pl,l,p1,p2);
	if(l == nullptr) return false;
	else{
		if(l->leaf) {
			delete l->item[*p2];
			for(short i = *p2; i<l->size-1; i++) l->items[i] = l->items[i+1];//может быть косяк
			l->items[l->size - 1] = nullptr;
			if(l->size < t){
				uniq(pl,l,pos1,pos2);
			}
			else {
				l->size--;
			}
		}
		else{
			container<T,V>* reserv;
			if(l->child[*pos2]->size > t-1){
				reserv = new container<T,V>(*(l->child[*pos2]->items[l->child[*pos2]->size - 1]));
				delete l->items[*pos2];
				l->items[*pos2] = reserv;
				delete_item(l->child[*pos2], reserv->key);
			}
			else{
				if(l->child[*pos2+1]->size > t-1){
					reserv = new container<T,V>(*(l->child[*pos2+1]->items[0]));
					delete l->items[*pos2];
					l->items[*pos2] = reserv;
					delete_item(l->child[*pos2+1], reserv->key);
				}
				else{
					merge(l, pl, pos1);
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

template<typename T, typename V, typename S>void btree<T,V,S>::split(S* f, S* nf, short p){
	S* res1 = new S(t);
	S* res2 = new S(t);
	short i;
	for(i=0; i<(t-1); i++){
		res1->items[i] = f->items[i];
		res2->items[i] = f->items[i+t];
		res1->child[i] = f->child[i];
		res2->child[i] = f->child[i+t];
	}
	res1->child[t-1] = f->child[t-1];
	res2->child[2*t-1] = f->child[2*t-1];
//	if(res1->ch()) res1->leaf = false;//not sure
//	if(res2->ch()) res2->leaf = false;
	for(i=nf->size(); i!=p; i--) {
		nf->items[i]=nf->items[i-1];
		nf->child[i+1]=nf->child[i];
	}
	nf->itemss[p+1] = f->items[t-1];
	nf->size++;
	delete f;
	nf->child[p+1] = res1;
	nf->child[p+2] = res2;
}
template<typename T,typename V typename S> void btree<T,V,S>::addINF(S* nod, T k, V v){
	if(nod == nullptr) nod = new S(t,k,v);
	else{
		short i;
		if(nod->leaf){
			for(i=nod->size(); i>=1 && k<nod->items[i-1]->key; i--) nod->items[i] = nod->items[i-1];//проверь потом
			nod->items[i] = new container<T,V>(k,v);
		}
		else{
			for(i = nod->size(); i>=0 && k<nod->items[i-1]->key;i--);//тут может быть косяк
			i++;
			if(nod->child[i]->full()){
				split(nod, nod->child[i], i);
				if(k>nod->keys[i]) i++;
			}
			addINF(nod->keys[i],k, v);
		}
	}
}
template<typename T, typename V, typename S> void btree<T,V,S>::add(T k, V v){
	if (root->full()){
		S* r = root;
		S* neW = new S(t);
		root = neW;
		root->leaf = false;
		root->child[0] = r;
		split(root, root->child[0], 0);
		addINF(root, k,v);
	}
	else{
		addINF(root, k);
	}
}
