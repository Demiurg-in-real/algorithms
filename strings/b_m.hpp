#pragma once
#include<vector>
#include<string>
namespace ALGS{
	class bm{
		private:
			size_t pos;
			std::vector<std::pair<char,int>> stop;
			std::vector<std::pair<std::string, unsigned int>> suf;
			void make_suf_stop(const std::string& ustr);
			void clear();
		public:
			bm();
			void search(const std::string& main, const std::string& submain, std::vector<int>& positions);
	};
	#include "b_m.tpp"
}
