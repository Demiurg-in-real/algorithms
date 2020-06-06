#pragma once
#include<vector>
#include<string>
#include "prefix.hpp"
class automat{
	private:
		std::vector<std::vector<std::pair<char,int>>> graph;
		std::string subs;
		void make_graph(std::string subs);
	public:
		automat();
		void search(const std::string& str, const std::string& substr, std::vector<int>& pos);
};
#include "automat.tpp"
