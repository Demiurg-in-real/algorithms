template <class K, class T> Node<K,T>::Node(K k, T v){
	key = k;
	value = v;
	left = nullptr;
	right = nullptr;
	height = 1;
}
template <class K, class T> Node<K,T>::Node(const Node &old){
	this->key = old.key;
	this->value = old.value;
	this->height = old.height;
	this->left = old.left;
	this->right = old.right;
}
template <class K, class T> Node<K,T>::~Node(){
	left = nullptr;
	right = nullptr;
}
