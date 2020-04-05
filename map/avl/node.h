#ifndef _AVL_
#define _AVL_
#include<stdio.h>
#include<stdint.h>
#include<iostream>
namespace AVLtree{	
	template <class K, class T> class Node{
		public:
			K key;
			T value;
			unsigned int height;
			int8_t balance;
			Node* root;
			Node* left;
			Node* right;
			Node(K k, T v);
			Node(const Node &old);
	};
	#include "node.tpp"
}
#endif
