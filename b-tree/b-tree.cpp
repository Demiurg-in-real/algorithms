#include "node.h"
#include<iostream>
#include<stack>
#include<utility>

template<typename T, typename S = node<T>> class btree{
	public:
		S* root;
		unsigned short t=0;
		void add(T key);
		void split(S* notful, S* ful);
		void addINF(S* nod, T k);
		void print();
		void prin(S* nod);
		btree(unsigned short step, T k){
			root = new S(step, k);
			t=step;
		}
};
template<typename T,typename S> void btree<T,S>::add(T key){
	if(root->full()){
		S* neW = new S(t);
		neW->child[0] = root;
		root=neW;
		root->leaf=false;
		split(root, root->child[0]);
		addINF(root, key);
	}
	else{
		addINF(root,key);
	}
}
template<typename T, typename S> void btree<T,S>::print(){
	prin(root);
}
template<typename T, typename S> void btree<T,S>::prin(S* nod){
	stack<pair<int,S*>> q;
	pair<int,S*> par;// = new(-30, root);
	q.push(std::make_pair(-30,root));
	while(!q.empty()){
		par=(q.top());
		q.pop();
		cout<<par.first<<": ";
		for(unsigned short i=0; i<par.second->size; i++) {
			cout<<par.second->keys[i]<<" , ";
			if(par.second->child[i] != NULL)q.push(std::make_pair(par.second->keys[i], par.second->child[i]));
		}
		if(par.second->child[par.second->size] != NULL) q.push(std::make_pair(par.second->keys[par.second->size-1], par.second->child[par.second->size]));
		cout<<endl;
	}
}

template<typename T,typename S> void btree<T,S>::split(S* notful, S* ful){
	S* res1 = new S(t);
	S* res2 = new S(t);
	unsigned short i,k;
	res1->cop(0,(t-1),ful);
	if(notful==root) {
		notful->keys.push_back(ful->keys[t-1]);
		notful->child[0] = res1;
		notful->child[1] = res2;
		}
	else{
			if(ful->keys[t-1] > notful->keys[notful->size-1]){
			notful->keys.push_back(ful->keys[t-1]);
			notful->size++;
		}
		else{
			for(i=0; i<(notful->size-1); i++){
				if(ful->keys[t-1] <= notful->keys[i]){
					for(k=(notful->size); k>i;k--){
						notful->keys[k] = notful->keys[k-1];
						notful->child[k+1] = notful->child[k];
					}
					notful->keys[i] = ful->keys[t-1];
					notful->child[i] = res1;
					notful->child[i+1] = res2;
					break;
				}
			}
		}
	}
	notful->size++;
	res1->cop(t,(2*t-1), ful);
	delete ful;
}
template<typename T,typename S> void btree<T,S>::addINF(S* nod, T k){
	if(nod == nullptr) nod = new S(t,k);
	unsigned short i;
	if(nod->leaf){
		for(i=(nod->size);k < nod->keys[i-1]; i--) {
			cout<<nod->keys[i-1]<<" = "<<endl;
			nod->keys[i] = nod->keys[i-1];//МОГУТ БЫТЬ КОСЯКИ!!!
		}
		nod->keys[i] = k;
	}
	else{
		for(i=(nod->size); k < nod->keys[i-1]; i--);
		if (nod->child[i]->full()){
			split(nod, nod->child[i]);
			if (k>nod->keys[i]) i++;
		}
		addINF(nod->child[i], k);
	}
}
int main(){
	btree<int> kek(2,4);
	for(int i=0; i<10; i++) kek.add(i);
	kek.print();
	return 0;
}
