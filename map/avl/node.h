#ifndef _AVL_
#define _AVL_
#include<stdio.h>
namespace AVLtree{	
	template <class K, class T> class Node{
		public:
			K key;
			T value;
			int height;
			Node* root;
			Node* left;
			Node* right;
			Node(K k, T v);
			Node(const Node &old);
	};
	#include "node.tpp"
}
#endif
