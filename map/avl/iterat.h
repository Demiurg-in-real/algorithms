#include<stack>
#include<vector>

#include "node.h"
#include "avl.h"
template<class K,class V, typename M = AVLtree::Node<K,V>/*, typename T = std::vector<M*>*/> class iterat{
	public:
		iterat(const M* ch,int i);
		iterat<K,V>& operator=(const iterat<K,V>& it);
		iterat<K,V>& operator++(iterat<K,V>& i);
		iterat<K,V>& operator--(iterat<K,V>& i);
		V& operator*();

	private:
		M* che;
		std::vector<M*> r;
		unsigned long siz;
		unsigned long pos;
		
};
#include "iterat.tpp"
