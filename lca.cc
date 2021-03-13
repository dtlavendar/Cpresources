struct lca {
	vector<vector<int>> Gr;
	vector<int> tint;
	vector<int> tout;
	vector<vector<int>> up;
	int timer=0;
	int l;

	void dfs(int x, int p) {
		tint[x]=++timer;
		up[x][0]=p;
		for(int L = 1; L < l; L++) {
			up[x][L]=up[up[x][L-1]][L-1];
		}
		for(int edge: Gr[x]) {
			if(edge != p)
				dfs(edge, x);
		}
		tout[x]=++timer;
	}
	bool is_ancestor(int u, int v) {
		return tint[u] <= tint[v] && tout[u] >= tout[v];
	}

	int get_lca(int u, int v) {
		if(is_ancestor(u, v))
			return u;
		else if(is_ancestor(v, u))
			return v;

		else {
			for(int i = l - 1; i >= 0; i--) {
				if(!is_ancestor(up[u][i], v))
					u = up[u][i];
			}

			return up[u][0];
		}
	}
	void addUniEdge(int u, int v) {
		assert(u >=0 && v >= 0 && u < Gr.size() && v < Gr.size());
		Gr[u].push_back(v);
		Gr[v].push_back(u);
	}
	void addDirEdge(int u, int v) {
		Gr[u].push_back(v);
	}

	void init(int N) {
		Gr.assign(N, vector<int>());
	}
	void process(int N, int root=0) {
		l = ceil(log2(N+0.0))+1;
		up.assign(N, vector<int>(l));
		
		tint.assign(N, 0);
		tout.assign(N, 0);
		timer=0;
		dfs(root, root);
	}
};
