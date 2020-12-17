#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <stack>
#include <set>
#include <vector>
#include <utility>

// COCO CHANNEL!

using namespace std;
#define send ios::sync_with_stdio(false);
#define help cin.tie(nullptr);
#define ll long long



// vector<int> parent;
// vector<int> level;
// void setUp(int n) {
// 	for(int i =0; i < n; i++)
// 		parent.push_back(i);

// 	for(int i =0; i < n; i++) {
// 		level.push_back(0);
// 	}
// }
// int find(int p) {
// 	if(p == parent[p]) 
// 		return p;
// 	return parent[p] = find(parent[p]);
// }
// bool connected(int x, int y) {
// 	return find(x) == find(y);
// }

// void unify(int first, int second) {
// 	int u = find(first);
// 	int v = find(second);

// 	if(u != v) {
// 		if(level[u] < level[v]) {
// 			swap(u, v);
// 		}
// 		parent[v] = u;
// 		if(level[u] == level[v]) {
// 			level[u]++;
// 		}
// 	}
// }


void solve();
int main() {
	send help

	int test_case;
	cin >> test_case;
	while(test_case--) 
		solve();
}

#define all(x) x.begin(),x.end()
#define sum(x) accumulate(all(x), 0)
void solve() {
	int a, b, c;cin >> a >> b >> c;

	vector<int> x = {a, b, c};
	sort(all(x));
	if(x[0] > ceil(x[1] + x[2] +6)/7) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}



// t
// d
// p
// e
// n
// c
// i
// l





