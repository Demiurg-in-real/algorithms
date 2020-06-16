#ifndef AVL
#define AVL
#include<queue>
#include<iostream>
#include<stack>
#include<cstdint>
#include<vector>
#include "node.h"
//#include "definit.h"
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
			bool check_rules(M* nod);
			M* cop_tree(M* nod);
		public:
			void clear_all();
			void insert(K key, V value);
			tree<K,V>& operator=(const tree<K,V>& rete);
			V operator[](K key);
			void delete_item(K key);
			tree();
			tree(K key, V value);
			tree(const tree<K,V> &sec);
			~tree();
			void print();
//			iterat<K,V>& begin(){
//				return iterat<K,V>(root,0);
//			}
//			iterat<K,V>& end(){
//				return iterat<K,V>(root,1);
//			}

	};
//	#include "iterat.h"
	#include "avl.tpp"
}
#endif
