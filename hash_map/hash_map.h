#ifndef __HASH_MAP__
#define __HASH_MAP__
#include "ser.h"
#include<cstdint>
#include<string>
#include<cmath>
#include<iostream>
namespace part_tree{
	template<typename K, typename V, typename M = serie<K,V>, typename W = unsigned long long> class hash_map{
		public:
			hash_map(){
				num_mem = 0;
				num_ser = 5;
				kek.resize(5);
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
			void print();
		private:
			void hash(W& i, K k);
			void hash(W& i, std::string k);
			int num_mem;
			int num_ser;
			double C;
			std::vector<M> kek;
			void sha256(W *res, std::string stri);
			void rehash(int ns);
			W mkint(std::string k);
	};
	#include "hash_map.tpp"
}
#endif
