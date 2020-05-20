void WFS::wfs(size_t start){
	std::stack<std::pair<bool,std::vector<int>>> que;
	que.push(gr[start]);
	std::pair<bool, std::vector<int>> x;
	while(!que.empty()){
		x = que.top();
		que.pop();
		for(size_t i = 0; i<gr.size();i++) {
			if(x == gr[i]){
				visited.push_back(i);
				gr[i].first = true;
				break;
			}
		}
		for(size_t i = 0; i<x.second.size();i++) if(!gr[x.second[i]].first) que.push(gr[x.second[i]]);
	}
}
