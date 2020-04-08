#ifndef AVL
#define AVL
#include<queue>
#include<iostream>
#include "node.h"
namespace AVL{
	template <class K, class V, typename M = AVLtree::Node<K,V>> class tree{
		private:
			void elevation(M* ob);
			template<class,class,typename> friend class tree;
			M* root;
			M* rotright(M* ob);
			M* rotleft(M* ob);
			M* search(M* ob, K key);
			M* insert(M* ob, K key, V value);
			M* balance(M* ob);
			M* finlef(M* ob);
			M* delete_item(M* ob, K key);
			bool df;
			int high(M* ob);
			bool is_empty();
			int bf(M* ob);
			void printi(M* treee, const int level);
		public:
			void insert(K key, V value);
			tree<K,V>& operator=(const tree<K,V>& rete);
			V operator[](K key);
			void delete_item(K key);
			tree(K key, V value);
			tree(const tree<K,V> &sec);
			~tree();
			void print();
	};
	#include "avl.tpp"
}
#endif
