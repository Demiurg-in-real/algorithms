#ifndef _SERI_
#define _SERI_
#include<vector>
namespace part_tree{
	template<typename K, typename V> class base{
		public:
			bool free;
			K key;
			V value;
			base(K k, V v){ key = k; value = v;}
			base(){
				free=true;
				key = K();
				value = V();
			};
			void insert(K k, V v){
				key = k;
				value = v;
				free = false;
			}
			void delet(){ free=true;};
	};
	template<typename K, typename V, typename obj = base<K,V>> class serie{
		public:
			serie();
			bool insert(K k, V v);
			bool delet(K k);
			const V& get(K k);
			short search(K k);
			bool empty();
			obj& operator[](int i);
			size_t siz(){return kek.size();}
		private:
			std::vector<obj> kek;
			short size;
			bool empt;
	};
	#include "ser.tpp"
}
#endif
