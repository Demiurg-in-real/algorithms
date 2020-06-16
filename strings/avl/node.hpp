#ifndef _AVLtree1_
#define _AVLtree1_
#include<stdio.h>
#include<stdint.h>
#include<iostream>
namespace AVLtree{	
	template <class K, class T> class Node{
		public:
			K key;
			T value;
			unsigned int height;
			Node* left;
			Node* right;
			Node(K k, T v);
			Node(const Node &old);
			~Node();
	};
	#include "node.tpp"
}
#endif
