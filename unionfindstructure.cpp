vector<int> parent;

void setUp(int n) {
	for(int i =0; i < n; i++)
		parent.push_back(i);
}
void find(int p) {
	while(p != parent[p]) {
		parent[p] = parent[parent[p]];
		p = parent[p];
	}
	return p;
}
bool connected(int x, int y) {
	return find(x) == find(y);
}

void unify(int first, int second) {
	int u = find(first);
	int v = find(second);

	if(u != v) {
		parent[u] = parent[v];
	}
}

