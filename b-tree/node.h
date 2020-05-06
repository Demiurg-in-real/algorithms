#include <vector>
using namespace std;
template<typename K, typename V> class container{
	public:
		K key;
		V value;
		container(K k, V v){ key=k; value=v;}
		container(container<K,V>& ob){
			this->key = ob.key;
			this->value = ob.value;
		}
};
template <typename K, typename V, typename S = container<K,V>> class node{
	public:
		bool leaf;
		unsigned short size = 0;
		unsigned short t;
		vector<S*> items;//K* keys;
		vector<node*> child;
		node(short step, K k, V v);
		node(short step);
		bool full();
		short siz();
		node(node<K,V,S>& ob);
//		bool ch();
//		void cop(unsigned short from, unsigned short to, node* ob);
};
#include "node.tpp"
