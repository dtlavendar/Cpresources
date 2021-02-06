struct lca {
	vector<vector<int>> edges;
	vector<int> levels;
	vector<bool> vis;
	vector<int> par;
	int n;
	
	void init(int s) {
		n = s;
		edges = vector<vector<int>> (n, vector<int>());
		vis = vector<bool> (n);
		par = vector<int> (n);
		levels = vector<int> (n, 0);
	}
	
	void addEdge(int x, int y) {
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	void setRoot(int cur, int p=0) {
		if(vis[cur]) return;
		vis[cur]=true;
		levels[cur]=p;
		
		for(int x: edges[cur]) {
			if(!vis[x]) {
				setRoot(x, p+1);
			}
		}
	}
	
	
	void lca(int x, int y) {
		int l = x, r = y;
		
		while(levels[l] > levels[r]) {
			for(auto edge: edges[l]) {
				if(levels[edge] < levels[l] && levels[edge] >= r) {
					l = edge;
					break;
				}
			}
		}
		while(levels[r] > levels[l]) {
			for(auto edge: edges[r]) {
				if(levels[edge] < levels[r] && levels[edge] >= l) {
					r = edge;
					break;
				}
			}
		}
		
		if(l == r) {
			return l;
		}
		
		while(l != r) {
			for(auto edge: edges[r]) {
				if(sz[edge] < sz[r]) {
					r=edge;
					break;
				}
			}
			for(auto edge: edges[l]) {
				if(sz[edge] < sz[l]) {
					l = edge;
					break;
				}
			}
		}
		// O(n) or log n?
		
		return l;
	}
};