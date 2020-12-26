#include <bits/stdc++.h>
using namespace std;
#define sz(a) int(a.size())
#define atoi(x) (x-'0')
#define cnst const
using ll = long long;

#define ar array
#define it int64_t
#define vt vector
const ll inf = ll(1e18);
#define pll pair<ll, ll>
#define sum(x) int(accumulate(x.begin(), x.end(), 0))
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define EACH(v, V) for (auto &v : V)
#define FOR(n) for (int i = 0; i < int(n); i++)
#define FORn(i, n) for (int i = 0; i < int(n); i++)
#define offset(V, i)  for (auto &v : V) v = i
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define minel(x) (*min_element(all(x)))
struct edge {
    ll from;
    ll to;
    ll cost;
};
bool operator<(edge t, edge f) {
    return t.cost > f.cost;
}
struct fast_mod
{

    int mod = 1e9 + 7;
    template <typename T>

    bool isEven(T x)
    {
        return !(x & 1);
    }
    template <typename T>
    bool isOdd(T x)
    {
        return x & 1;
    }
    int addmod(int x, int y, int m)
    {
        // simple mod addition
        return ((x % m) + (y % m)) % m;
    }
    int multmod(int x, int y, int m)
    {
        return ((x % m) * (y % m)) % m;
    }
    int submod(int x, int y, int m)
    {
        return ((x % m) - (y % m)) % m;
    }
    int regmod(int x)
    {
        // now just do whatever
        return x % mod;
    }
};
struct bintree
{
    struct bintree *left;
    struct bintree *right;
    int val;
    bintree(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};
namespace graph_theory {
	void fast_io() {
		ios::sync_with_stdio(false);cin.tie(nullptr);
	}
	ll djikstra(vector<pll> adjList[], int totalNodes, int u, int v) {
		priority_queue<pll, vt<pll>, greater<pll>> pq;
		// assuming adjList is {cost, node};
		vt<ll> dist(200000, inf);
		dist[u] = 0;
		vt<bool> vis(200000, 0);
		while(pq.size()) {
			ll t = pq.top().second;
			pq.pop();
			if(vis[t]) continue;
			vis[t]=1;
			for(auto &edge: adjList[t]) {
				ll x = edge.first;
				ll y = edge.second;
				if(dist[y] > dist[t] + x) {
					dist[y] = dist[t] + x;
					pq.push({dist[y], y});
				}
			}
		}
		return dist[v];
	}
	void bfs(vector<ll> adjList[], vt<bool> &vis, int n) {
		queue<int> s;
		s.push(n);
		while(s.size()) {
			int a = s.front();
			s.pop();
			if(vis[a]) continue;
			vis[a]=true;
			for(auto &edge: adjList[a]) {
				s.push(edge);
			}
		}
	}
	void dfs(vector<ll> adjList[], vt<bool>& vis, int n) {
		stack<int> curNodes;
		curNodes.push(n);
		while(curNodes.size()) {
			int t = curNodes.top();
			curNodes.pop();
			if(vis[t]) continue;
			vis[t]=true;
			for(auto &edge: adjList[t]) {
				curNodes.push(edge);
			}
		}
	}
}
#define psh push

#define pb push_back
struct segtree
{

    struct segtree *lChild;
    struct segtree *rChild;
    ll sum;
    int leftmost, rightmost;
    segtree(int left, int right, vector<int> &arr)
    {

        leftmost = left;
        rightmost = right;
        if (left == right)
        {
            sum = arr[left];
        }
        else
        {
            int mid = (left + right) / 2;

            lChild = new segtree(left, mid, arr);
            rChild = new segtree(mid + 1, right, arr);
            this->update();
        }
    }
    void update(){
        if(leftmost==rightmost) return;
        sum=lChild->sum+rChild->sum;
    }
    void pointUpdate(int index, int newVal) {
        if(leftmost==rightmost) {
            sum=newVal;
            return;
        }
        if(index<=lChild->rightmost) lChild->pointUpdate(index, newVal);
        else rChild->pointUpdate(index, newVal);
        update();
    }
    ll query(int left, int right)
    {

        if (left > rightmost || right < leftmost)
        {
            return 0LL;
        }
        else if (left <= leftmost && right >= rightmost)
            return sum;

        return lChild->query(left, right) + rChild->query(left, right);
    }
};
struct udGraph {
    vector<vector<int>> adjList;
    vector<bool> vis;
    int size;
    udGraph(int n) {
        this->size = n;
        vis.resize(n);
        adjList.resize(n);
    }
    void addNodes(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void dfs(int n) {
        vis[n]=true;
        for(auto &edge: adjList[n]) if(!this->vis[edge]) dfs(edge);
    }
    bool connected() {
        this->dfs(0);
        int n = this->size;
        for(int i =0; i < n; i++)
            if(!this->vis[i]) return false;
        return true;
        // O(n)
    }

};
template<typename T> 
bool binsearch(vector<T> &nums, int target)
{

    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return true;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
namespace number_theory {
	vector<int> sieve(int n) {
		bool prime[15000105];
        for(int i =0; i < n; i++) prime[i]=1;
		for(int i = 2; i <= n; i++)if(prime[i]) for(int j=i*i; j <= n; j+=i) prime[j]=0;
		vector<int> ans;
		for(int i =2; i <=n; i++) if(prime[i]) ans.push_back(i);
		return ans;
	}
    vector<ll> pfactors(int n) {
        vector<ll> pf;
        for(ll i = 2; i < n/2; i++) {
            int c=0;
            while(n%i==0) {
                c++;
                n/=i;
            }
            if(c) pf.push_back(i);
        }
        return pf;
        // O(sqrt(n))
    }
    bool isPrime(int n) {
        if(n == 1) return false;
        if(n == 2) return true;
        if(n == 3) return true;
        if(n%3 ==0 || n%2==0) return false;
        for(int i = 5; i * i <=n; i+=6) {
            if(n % i ==0 || n % (i+2) ==0) return false;
        }
        return true;
    }

}

void solve()
{
	int n;
	cin >> n;
}
int main()
{
    fastio;

    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}
