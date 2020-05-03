#ifndef _SERI_
#define _SERI_
#include<vector>
namespace part_tree{
	template<typename K, typename V> class base{
		public:
			bool free;
			K key;
			V value;
			base(K k, V v){ free = false; key = k; value = v;}
			base(){
				free=true;
				key = K();
				value = V();
			};
	};
	template<typename K, typename V, typename obj = base<K,V>> class serie{
		public:
			serie();
			int search(K k);
			bool empt;
			unsigned int size;
			bool empty();
			obj& operator[](unsigned long long k);
			size_t siz(){return kek.size();}
			void resiz();
		private:
			std::vector<obj> kek;
	};
	#include "ser.tpp"
}
#endif
