#include<math.h>
#include<queue>
#include<iostream>
using namespace std;
#include "node.h"
#include "../../binaryHeap/title.h"
template <class K, class V, typename M = AVLtree::Node<K,V>> class tree{
	private:
		void elevation(M* ob);
		M* root;
		M* rotright(M* ob);
		M* rotleft(M* ob);
		M* search(M* ob, K key, V value);
		M* insert(M* ob, K key, V value);
		M* balance(M* ob);
		M* finlef(M* ob);
		M* delete_item(M* ob, K key, V value);
		bool df;
		bool is_empty();
		int high(M* ob);
		int bf(M* ob);
		void printi(M* treee, const int level);
	public:
		bool insert(K key, V value);
		void delete_item(K key, V value);
		tree(K key, V value);
		tree(M &ob);
		void print(int i);
};
template <class K, class V, typename M> tree<K,V,M>::tree(K key, V value){
	root = new M(key, value);}
template <class K, class V, typename M> M* tree<K,V,M>::search(M* ob, K key, V value){
	if(ob == nullptr) return nullptr;
	if(ob->value == value && ob->key == key) return ob;
	else{
		if(ob->key > key)return search(ob->right,key,value);
		if(ob->key < key)return search(ob->left,key,value);
	}
}
template <class K, class V, typename M> M* tree<K,V,M>::insert(M* ob, K key, V value){
	if(ob==nullptr) return new M(key, value);
	if(key>ob->key)	ob->right = insert(ob->right,key,value);
	else{
		if(key<ob->key)	ob->left = insert(ob->left,key,value);
		else{
			if(ob->key == key) ob->value = value;
		}
	}
	return balance(ob);
}
template <class K, class V, typename M> int tree<K,V,M>::high(M* ob){return ob!=nullptr?ob->height:0;}
template <class K, class V, typename M> void tree<K,V,M>::elevation(M* ob){ ob->height =1 + (high(ob->left)>high(ob->right)?high(ob->left):high(ob->right));}
template <class K, class V, typename M> int tree<K,V,M>::bf(M* ob){
	ob->balance = high(ob->left) - high(ob->right);
	return ob->balance;
}
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
	cout<<"Key "<<ob->key<<" height is "<<ob->height<<endl;
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
template <class K, class V, typename M> bool tree<K,V,M>::is_empty(){
	if(root == nullptr) return true;
	else return false;
}
template <class K, class V, typename M>  tree<K,V,M>::tree(M &sec){
	//&sec = new tree<K,V>(this->root->key, this->root->value);
	(*this)=sec;
	role<M*> que;
	M* x;
	que.push(this->root);
	while(!que.empty()){
		x = que.pop();
		sec.insert(x->key, x->value);
		if(x->left != nullptr) que.push(x->left);
		if(x->right != nullptr) que.push(x->right);
	}
}
template <class K, class V, typename M> M* tree<K,V,M>::finlef(M* ob){
	if(ob->left->left == nullptr) return ob;
	return finlef(ob->left);
}
//--------------------------------------------
template <class K, class V, typename M> M* tree<K,V,M>::delete_item(M* ob, K key, V value){
	if(key>ob->key)ob->right = delete_item(ob->right, key,value);
	else{
		if(key<ob->key) ob->left = delete_item(ob->left,key,value);
		else{
			if(key != ob->key) {
				df = true;
				return ob;
			}
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
					res->right = delete_item(ob->right, res->key, res->value);
				}
			}
			delete ob;
			return balance(res);
		}
	}
	return balance(ob);
}
template<class K, class V, typename M>void tree<K,V,M>::printi(M *treee, int level)
{      
    if (treee->right) printi(treee->right, level + 1);
    for (int i = 0; i < level; i++) std::cout << " ";
    std::cout << treee->key << std::endl;
    if (treee->left) printi(treee->left, level + 1);
}
template<class K, class V, typename M> void tree<K,V,M>::print(int i){
	printi(root,0);
}
					
//-----------------------public------------------------
template <class K, class V, typename M> bool tree<K,V,M>::insert(K key, V value){
	if(search(root, key,value) != nullptr) return false;
	root = insert(root, key,value);
	print(0);
	cout<<"---------------------------"<<endl;
	return true;
}
template <class K, class V, typename M> void tree<K,V,M>::delete_item(K key, V value){
	delete_item(root,key,value);
	if(df == true) {
		std::cerr<<"Can't find this object!"<<std::endl;
		df = false;
	}
	else std::cout<<"Success."<<std::endl;
	print(0);
}
int main(){
	AVLtree::Node<int,int> kek(1,11);
	AVLtree::Node<int,int> kuk = kek;
//	printf("%p - test real\n%p - test copied", &kek,&kuk);
	tree<int,int> lol(9,5);
	lol.insert(2,6);
	lol.insert(7,3);
	lol.insert(8,1);
	lol.insert(4,4);
	lol.insert(1,4);
	lol.insert(10,12);
	lol.insert(12,12);
	lol.insert(11,1);
	lol.delete_item(9,5);
	lol.delete_item(12,12);
	lol.delete_item(11,1);
	lol.delete_item(10,12);
	return 0;
}
