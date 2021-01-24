#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
struct lz_segtree {
    ll cur;
    ll lazy_update;
    struct lz_segtree* lchild;
    struct lz_segtree* rchild;

    int leftmost, rightmost;

    lz_segtree(int l, int r, vector<int64_t> &sps) {
        leftmost = l;
        rightmost = r;
        lazy_update = 0;
        if(l == r)
            cur = sps[l];
        else {
            int mid = (l + r) / 2;
            lchild = new lz_segtree(l, mid, sps);
            rchild = new lz_segtree(mid+1, r, sps);

            update();
        }
    }
    void update() {
        cur = max(lchild->cur, rchild->cur);
    }
    
    void range_update(int l, int r, int val) {
        if(l > rightmost || r < leftmost) return;
        else if(l <= leftmost && r>=rightmost) {
            lazy_update += val;
            return;
        }
        int mid = (l + r) / 2;
        lchild->range_update(l, mid, val);
        rchild->range_update(mid+1, r, val); 
    }

    ll query(int l, int r) {
        if(l > rightmost || r < leftmost)
            return INT_MIN;
        else if(l <= leftmost && r>=rightmost) {
            return cur + lazy_update;
        }
        // O-> O, O = 3 values
        // {3, 5} -> {8} 0, 0 3 1, 1
        //
        return max(lchild->query(l, r) , rchild->query(l, r));

    }

    
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for(int i=0; i < n; i++) cin >> a[i];

    vector<ll> pref(n);
    for(int i =0; i < n; i++) pref[i] = a[i];


    for(int i = 1; i < n; i++) pref[i] += pref[i-1];
    lz_segtree lz(0, n-1, pref);
    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int pos, val;
            cin >> pos >> val;
            --pos;
            ll dist = val - a[pos];
            lz.range_update(pos, n-1, dist);
            a[pos] = val;
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;

            cout << lz.query(l, r) << "\n";
        }
    }

}
