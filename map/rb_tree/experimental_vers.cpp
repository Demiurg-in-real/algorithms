#include<stdio.h>
#include<string>
template <class K, class V> class Node{
	K key;
	V value;
	int height;
	Node* left;
	Node* right;
	Node(K k, V v){
		key = k;
		value = v;
		left=nullptr;
		right=nullptr;
		height=1;
	}
};
template <class K, class V> struct node{
//	unsigned color:1;
	unsigned left:(sizeof(node*));
	unsigned right:(sizeof(node*));
	unsigned height:32;
	unsigned key:(sizeof(K*));
	unsigned value:(sizeof(V*));
	node(K k, V v){
		key = &k;
		value = &v;
		left=0;
		right=0;
		height = 1;
	}
}__attribute__((packed));
int main(){
	node<int,std::string> lol(1,"Ha!");
	lol.height=0xff;
	printf("%d\n%i\n%d - %d\n", lol.height, sizeof(std::string*), sizeof(node<std::string,std::string>), sizeof(Node<std::string,std::string>));
	return 0;
}
