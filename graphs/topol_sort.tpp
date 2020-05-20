void topol_sort::dfs_m(std::stack<int>& q,int index){
	gr[index].first = true;
	for(size_t i =0; i<gr[index].second.size(); i++)
		if(!gr[gr[index].second[i]].first)
			dfs_m(q,gr[index].second[i]);
	q.push(index);
}

void topol_sort::topological_sort(){
	std::stack<int> que;
	for(size_t i = 0; i<gr.size(); i++)
		if(!gr[i].first)
			dfs_m(que, i);
	sorted.resize(0);
	while(!que.empty()){
		sorted.push_back(que.top());
		que.pop();
	}
}
