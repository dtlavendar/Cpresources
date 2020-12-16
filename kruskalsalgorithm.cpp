#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<array<int, 3>> edgelist;
// test
vector<int> parent;

void setUp(int n) {
	for(int i =0; i < n; i++)
		parent.push_back(i);
}
int find(int p) {
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


int kruskal() {
	sort(edgelist.begin(), edgelist.end(), 
		[](const auto &a, const auto &b) {
			return a[2] < b[2];
		}
		// sort by decreasing nums
	);
	// from, to, cost
	
	int ptr=0;
	// vector<array<int, 2>> ans;
	int n = edgelist.size();
	int num=0;

	while(ptr < n) {
		if(!connected(edgelist[ptr][0], edgelist[ptr][1])) {
			unify(edgelist[ptr][0], edgelist[ptr][1]);
			// array<int, 2> a = {edgelist[ptr][0], edgelist[ptr][1]};
			// ans.push_back(a);
			num+=edgelist[ptr][2];
		} 
		ptr++;
	}
	// deliver evefything yeeeee
	return num;
}

int main() {
	int n,m;
	cin >> n >> m;
	setUp(n);
	for(int i =0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		edgelist.push_back({a, b, cost});
	}
	int ans = kruskal();

	cout << ans;
}