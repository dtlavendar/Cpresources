vector<int> adjList[200000];

bool vis[200000];

void bfs(int node) {
	queue<int> toTravel;

	toTravel.push(node);
	while(toTravel.size()) {
		int t = toTravel.front();
		toTravel.pop();

		if(vis[t]) continue;
		vis[t]=true;
		// make sure there is no tle
		for(auto &edge: adjList[t]) toTravel.push(edge);
	}
}