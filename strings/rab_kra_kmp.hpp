#pragma once
#include<vector>
#include<string>
#include<cmath>
#include "prefix.hpp"
namespace ALGS{
	void rabin_kramp(const std::string& str, const std::string& substr, std::vector<int>& pos);
	void KMP(const std::string& str, const std::string& substr, std::vector<int>& pos);
	#include "rab_kra_kmp.tpp"
}
