void DFS::dfs(size_t index){
	visited.push_back(index);
	gr[index].first = true;
	for(size_t i = 0; i<gr[index].second.size(); i++)
		if(!gr[gr[index].second[i]].first) 
			dfs(gr[index].second[i]);
}
