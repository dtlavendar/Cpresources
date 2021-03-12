
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;
typedef long long ll; 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define ar array

int A[200000];
int N, Q;

template<class T, int _SZ>
struct rangeQ {

    static const int _T =_SZ;
    static const int R = (int)log2(_T);

    T st[_T+5][R+2];
    ll logs[_T+5];

    void init(int a[], int s, function<T(T, T)> &b) {
        memset(st, 0x3f, sizeof(st));
        for(int i = 0; i < int(s); i++)
            st[i][0]=a[i];

        for(int j = 1; j <= R; j++)
            for(int i = 0; i + (1 << j) <= _T; i++)
                st[i][j] = b(st[i][j-1], st[i + (1 << (j-1))][j-1]);

        logs[1]=0;
        for(int i = 2; i <= _T; i++) {
            logs[i]=logs[i/2]+1;
        }
    }
    
    ll rangeSum(int l, int r) {
        ll sum = 0;
        for(int j = R; j >= 0; j--) {
            if((1 << j) <= r - l + 1) {
                sum += st[l][j];
                l += (1 << j);
            }
        }
        return sum;
    }

    ll rangeMin(int l, int r) {
        ll j = logs[r-l+1];
        ll res = min(st[l][j], st[R - (1 << j) + 1][j]);
        return res;
    }

    ll rangeMax(int l, int r) {
        ll j = logs[r-l+1];
        ll res = max(st[l][j], st[R - (1 << j) + 1][j]);
        return res;
    }

    ll rangeFun(int l, int r, function<T(T, T)> &b) {
        ll j = logs[r-l+1];
        ll res = b(st[l][j], st[R - (1 << j) + 1][j]);
        return res;
    }


};
const int P = 10000;
void solve() {
	cin >> N >> Q;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    rangeQ<int, P> sparse_table;
    function<int(int, int)> d = [&](int x, int y) -> int {
        return min(x, y);
    };
    sparse_table.init(A, N, d);
    for(int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
       	l++, r++;
        cout << sparse_table.rangeMin(l, r) << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T = 1; //cin >> T;
   
    while(T--)
        solve();
}
