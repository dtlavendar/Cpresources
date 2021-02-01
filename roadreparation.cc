#include <bits/stdc++.h>
 
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> g(n);
    vector<bool> v(n);
    vector<array<int, 3>> edgelist;
 
    vector<int> parent(n);
    vector<int> size(n);
    for(int i = 0;i < n ; i++)parent[i] = i;
 
    function<int(int)> find = [&](int n) {
        if( parent[n] == n ) return n;
        return parent[n] = find(parent[n]);
    };
    function<void(int, int)> unify = [&](int x, int y) {
        int u = find(x);
        int v = find(y);
 
        if( u != v ) {
            if(size[u] < size[v]) swap(u, v);
            parent[v] = u;
            if(size[u] == size[v])
                size[u]++;
        }
    };
    auto connected = [&](int x, int y) {
        return find(x) == find(y);
    };
 
    for(int i =0 ; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        --a, --b;
        g[a].push_back({b, cost});
        g[b].push_back({a, cost});
        edgelist.push_back({a, b, cost});
    }
    function<void(int)> dfs = [&](int x) {
        v[x]=true;
        for(auto &edge: g[x]) if(!v[edge[0]]) dfs(edge[0]);
    };
    sort(edgelist.begin(), edgelist.end(), [&](const auto a, const auto b) {
            return a[2] < b[2];
            });
    dfs(0);
    bool works = true;
    for(int i = 0; i < n; i++)
        works &= v[i];
    if(!works) {
        cout << "IMPOSSIBLE";
        return 0;
    }
 
    int64_t ans = 0;
    int ptr = 0;
 
    while(ptr < m) {
        int u = edgelist[ptr][0];
        int v = edgelist[ptr][1];
        int cost = edgelist[ptr][2];
 
        if(!connected(u, v)) {
            unify(u, v);
            ans += cost;
        }
        ptr++;
    }
    cout << ans << "\n";
}
