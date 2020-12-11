#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5+1;
long long inf = 1e18;
#define ll long long

vector<pair<long long, long long>> adjList[mxN];
bool vis[mxN];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
int main() {
	ll n, m;
	cin >> n >> m;
	ll dist[n];
	for(int i =0; i < m; i++){
		long long a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		adjList[a].push_back({c, b});
	}
	for(int i=0;i<n;i++)dist[i]=inf;
	dist[0]=0;
	pq.push({0, 0});
	
	while(pq.size()) {
		long long node = pq.top().second;
		pq.pop();
		if(vis[node]) continue;
		vis[node]=true;
		for(auto &e: adjList[node]) {
			if(e.first + dist[node] < dist[e.second]) {
				dist[e.second]=dist[node]+e.first;
				pq.push({dist[e.second], e.second});
			}
		}
	}
	for(int i=0;i<n;i++){
		cout << dist[i] << " ";
	}
	// 
}
