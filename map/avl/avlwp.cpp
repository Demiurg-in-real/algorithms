#include<queue>
#include<iostream>
#include "node.h"
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
		bool insert(K key, V value);
		tree<K,V>& operator=(const tree<K,V>& rete);
		V operator[](K key);
		void delete_item(K key);
		tree(K key, V value);
		tree(const tree<K,V> &sec);
		~tree();
		void print(int i);
};
template<class K, class V, typename M> tree<K,V>& tree<K,V,M>::operator=(const tree<K,V>& rete){ return tree(rete);}
template<class K, class V, typename M> V tree<K,V,M>::operator[](K key){ 
	M* kr = search(root,key);
	if(kr != nullptr) return kr->value;
//	return NULL;
}
template<class K, class V, typename M> tree<K,V,M>::~tree(){
	while(!is_empty()){
		root = delete_item (root, root->key);
	}
}
template <class K, class V, typename M> tree<K,V,M>::tree(K key, V value){
	root = new M(key, value);}
template <class K, class V, typename M> M* tree<K,V,M>::search(M* ob, K key){
	if(ob == nullptr) return nullptr;
	if(ob->key == key) return ob;
	if(ob->key > key)return search(ob->left,key);
	if(ob->key < key)return search(ob->right,key);
}
template <class K, class V, typename M> M* tree<K,V,M>::insert(M* ob, K key, V value){
	if(ob==nullptr) return new M(key, value);
	if(key>ob->key)	ob->right = insert(ob->right,key,value);
	if(key<ob->key)	ob->left = insert(ob->left,key,value);
	if(ob->key == key) ob->value = value;
	return balance(ob);
}
template <class K, class V, typename M> int tree<K,V,M>::high(M* ob){return ob!=nullptr?ob->height:0;}
template <class K, class V, typename M> void tree<K,V,M>::elevation(M* ob){ ob->height =1 + (high(ob->left)>high(ob->right)?high(ob->left):high(ob->right));}
template <class K, class V, typename M> int tree<K,V,M>::bf(M* ob){ return high(ob->left) - high(ob->right);}
template <class K, class V, typename M> M* tree<K,V,M>::rotright(M* ob){
	M* swap = ob->left;
	ob->left = swap->right;
	swap->right = ob;
	elevation(swap->right);
	elevation(swap);
	return swap;
}
template <class K, class V, typename M> M* tree<K,V,M>::rotleft(M* ob){
	M* swap = ob->right;
	ob->right = swap->left;
	swap->left = ob;
	elevation(swap->left);
	elevation(swap);
	return swap;
}
template <class K, class V, typename M> M* tree<K,V,M>::balance(M* ob){
	elevation(ob);
	if(bf(ob) == 2){
		if(bf(ob->left) < 0) ob->left = rotleft(ob->left);
		return rotright(ob);
	}
	if(bf(ob) == -2){
		if(bf(ob->right) > 0)ob->right = rotright(ob->right);
		return rotleft(ob);
	}
	return ob;
}
template <class K, class V, typename M> bool tree<K,V,M>::is_empty(){return ((root == nullptr)?(true):(false));}
template <class K, class V, typename M> M* tree<K,V,M>::finlef(M* ob){return(ob->left->left == nullptr)?(ob):(finlef(ob->left));}
template <class K, class V, typename M> M* tree<K,V,M>::delete_item(M* ob, K key){
	if(ob == nullptr) {
		df = true;
		return nullptr;
	}
	if(key>ob->key)ob->right = delete_item(ob->right, key);
	if(key<ob->key) ob->left = delete_item(ob->left,key);
	if(key == ob->key){
		if(ob->left == nullptr && ob->right == nullptr) {
			delete ob;
			return nullptr;
		}
		M* res;
		if(ob->right == nullptr)res = ob->left;
		else{
			if(ob->right->left == nullptr){
				res = ob->right;
				res->left=ob->left;
			}
			else{
				M* rese = finlef(ob->right);
				res = new M(rese->left->key,rese->left->value);
				res->left = ob->left;
				res->right = delete_item(ob->right, res->key);
			}
		}
		delete ob;
		return balance(res);
	}
	return balance(ob);
}
template<class K, class V, typename M> tree<K,V,M>::tree(const tree<K,V> &sec){
	std::queue<M*> que;
	this->root= new M(sec.root->key, sec.root->value);
	if(sec.root->left != nullptr)que.push(sec.root->left);
	if(sec.root->right != nullptr) que.push(sec.root->right);
	M* x;
	while(!que.empty()){
		x = que.front();
		this->root = insert(this->root,x->key,x->value);
		que.pop();
		if(x->left != nullptr) que.push(x->left);
		if(x->right != nullptr) que.push(x->right);
	}
}
template<class K, class V, typename M>void tree<K,V,M>::printi(M *treee, int level)
{      
    if (treee->right) printi(treee->right, level + 1);
    for (int i = 0; i < level; i++) std::cout << "-";
    std::cout << treee->key << std::endl;
    if (treee->left) printi(treee->left, level + 1);
}
template<class K, class V, typename M> void tree<K,V,M>::print(int i){printi(root,0);}
					
//-----------------------public------------------------
template <class K, class V, typename M> bool tree<K,V,M>::insert(K key, V value){
	if(search(root, key) != nullptr) return false;
	root = insert(root, key,value);
//	print(0);
	return true;
}
template <class K, class V, typename M> void tree<K,V,M>::delete_item(K key){
	root = delete_item(root,key);
	if(df == true) {
		std::cerr<<"Can't find this object!"<<std::endl;
		df = false;
	}
	else std::cout<<"Success."<<std::endl;
}
int main(){
//	AVLtree::Node<int,int> kek(1,11);
	tree<int,int> lol(50,5);
	for(int i=1; i<10; i++) if(lol.insert(i,i) == false) std::cout<<"Fuck...\n";
	lol.print(0);
	std::cout<<lol[500];
//	tree<int,int> kek=lol;
//	printf("%p\n%p\n", &kek, &lol);
/*	lol.insert(2,6);
	lol.insert(7,3);
	lol.insert(8,1);
	lol.insert(4,4);
	lol.insert(1,4);
	lol.insert(10,12);
	lol.insert(12,12);
	lol.insert(11,1);
	lol.insert(11,3);
	lol.insert(11,3);
*///	lol.print(0);
//	tree<int, int> rer(lol);
	
//	lol.print(0);
//	lol.delete_item(444,5);
//	lol.delete_item(5000,12);
//	lol.delete_item(11,1);
//	lol.delete_item(10,12);
	return 0;
}
