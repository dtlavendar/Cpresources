#include<bits/stdc++.h>
#define pq priority_queue
// lmao just give up
using namespace std;
const int mxN = 2e5+5;
bool vis[mxN];
vector<pair<long long, long long>> adjList[mxN];
const long long INF = 1e16;
void djistrka(long long start, long long end){
    pq<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;

    
    long long dist[start];
    for(int i = 0; i < end; i++) dist[i]=INF;
    dist[start]=0;
    q.push({start, 0});
    while(q.size()) {
        pair<long long, long long> ans = q.top();
        q.pop();
        int node = ans.second;
        if(vis[node]) continue;
        vis[node]=true;
        
        for(auto &e: adjList[node]){
            if(dist[e.second] > dist[node] + e.first){
                dist[e.second]=dist[node]+e.first;
                q.push({dist[e.second], e.second});
            }
        }
    }
    cout << dist[end];
}
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i =0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adjList[a].push_back(b);
    }
    vector<pair<long long, long long>> queries;
    for(int i =0; i < q; i++){
        long long a, b;
        cin >> a >> b;
        queries.push_back(make_pair(a, b));
    }
    for(auto &e: queries){
        djikstra(a, b);
    }
}
