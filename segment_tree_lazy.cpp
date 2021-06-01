#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T>
struct segment_tree {
    vector<T> tree, lazy;
    vector<T> a;
    int SZ;
    segment_tree(vector<int> &v) {
        int s = int(v.size());
        assert(s == (int)a.size());
        tree.resize(s << 1);
        lazy.resize(s << 1);
        SZ = s;
        a = v;
    }
    T combine(int t1, int t2) {
        return t1 + t2;
    }
    void build(int rt, int t1, int t2) {
        if(t1 == t2) {
            tree[rt] = a[rt];
            lazy[rt] = 0;
        } else {
            int mid = (t1 + t2) >> 1;
            build(rt << 1, t1, mid);
            build(rt << 1 | 1, mid + 1, t2);
            tree[rt] = combine(tree[rt << 1], tree[rt << 1 | 1]);
            push(rt);
        }
    }
    
    void init() {
        build(1, 0, SZ - 1);
    }

    void push(int val) {
        tree[val << 1] += val;
        tree[val << 1 | 1] += val;
        lazy[val << 1] += val;
        lazy[val << 1 | 1] += val;
        lazy[val] = 0;
    }

    void update(int rt, int t1, int t2, int l, int r, int val) {
        if(l > t2 || r < t1) {
            return;
        }
        if(l <= t1 && r >= t2) {
            tree[rt] += val;
            lazy[rt] += val;
        } else {
            int mid = (t1 + t2) >> 1;
            update(rt << 1, t1, mid, l, r, val);
            update(rt << 1 | 1, mid + 1, t2, l, r, val);
            push(rt);
        }
    }
    T query(int rt, int t1, int t2, int l, int r) {
        if(r < t1 || l > t2) return 0;

        else if(l <= t1 && r >= t2) return tree[rt];

        else {
            int mid = (t1 + t2) >> 1;
            push();
            return query(rt << 1, t1, mid, l, r) + query(rt << 1 | 1, mid + 1, t2, l, r);
        }
    }

    T query(int l, int r) { return query(1, 0, SZ - 1, l, r); }

    T query(int pos) { return query(1, 0, SZ - 1, pos, pos); }

    void update(int l, int r, int x) { update(1, 0, SZ - 1, l, r, x); }
    void update(int pos, int x) { update(1, 0, SZ - 1, pos, pos, x); }
};