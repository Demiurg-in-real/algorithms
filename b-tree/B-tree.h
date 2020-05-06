#include "node.h"
#include<iostream>
using namespace std;
template<typename T, typename V, typename S = node<T,V>> class btree{
	public:
		btree(unsigned short t, T k, V v);
		bool is_empty();
		btree(const S& ob);
		btree<T,V,S>& operator=(const btree<T,V,S>& ne);
		V& operator[](T k);
		~btree();
		void clear_all();
		void clear(S* nod);
		bool search(S* nod, T k, S* prelast, S* last, int& pos1,int& pos2);
		void merge(S* now, S* upper, int& pos1);
		void traversal_right(S* prelast, S* last, int& pos1);
		void traversal_left(S* prelast, S* last, int& pos1);
		void uniq(S* prelast, S* last, int& pos1, int& pos2);
		container<T,V>& nearer(bool where, S* from);
		bool delete_item(S* r,T k);
		void split(S* f, S* nf, short p);
		void addINF(S* nod, T k, V v);
		void add(T k, V v);
		short t;
		S* root;
};
#include "B-tree.tpp"
