#ifndef __HASH_MAP__
#define __HASH_MAP__
#include "ser.h"
#include<cstdint>
#include<string>
namespace part_tree{
	template<typename K, typename V, typename M = serie<K,V>, typename W = uint8_t> class hash_map{
		public:
			hash_map(){
				num_mem = 0;
				num_ser = 1000;
				kek.resize(1000);
				C = 2.0;
			};
			bool insert(K k, V v);
			hash_map<K,V> operator=(const hash_map<K,V>& cop);
			V& operator[](K k);
			bool delet(K k);
			const size_t size();
			double& get_C();
			const double real_C();
			void delete_all();
		private:
			int num_mem;
			int num_ser;
			double C;
			std::vector<M> kek;
			void sha256(W *res, std::string stri);
			void rehash(int ns);
	};
	#include "hash_map.tpp"
}
#endif
