template<class C>
struct segment_tree {
	const ll INF = 1e18;
	vector<C> A;
	constexpr static int T=2e5;
	segment_tree(vector<C> &B) {
		for(auto &e: B) A.push_back(e);
		T = A.size() + 1;
	}
	struct seg {
		ll lz, mn;
	} st[2*T];
	
	void push(int v) {
		st[2*v].mn += st[v].lz;
		st[2*v].lz += st[v].lz;
		st[2*v+1].mn += st[v].lz;
		st[2*v+1].lz += st[v].lz;
		st[v].lz = 0;
	}
	void build(int r1, int t1, int t2) {
		if(t1 > t2) return;
		if(t1 == t2) {
			st[r1].mn = A[t1];
		} else {
			int mid = (t1 + t2) / 2;
			build(2*r1, t1, mid);
			build(2*r1+1, mid+1, t2);
			st[r1].mn  = min(st[2*r1].mn, st[2*r1+1].mn);
			// t1 and t2 are 0 based
		}
	}
	ll rangeQuery(int r1, int t1, int t2, int l, int r) {
		if(l > t2 || r < t1) return INF;
		else if(t1 <= l && t2 >= r) {
			return st[r1].mn;
		} else {
			int mid = (l + r) / 2;
			push(r1);
			return min(rangeQuery(2*r1, t1, mid, l, r), rangeQuery(2*r1+1, mid+1, t2, l, r));
		}
	}

	void update(int r1, int t1, int t2, int pos, int val) {
		if(t1 == t2) {
			st[r1].mn += val;
		} else {
			int mid = (t1 + t2) / 2;
			if(pos <= mid) {
				update(r1*2, t1, mid, pos, val);
			} else {
				update(r1*2+1, mid+1, t2, pos, val);
			}
		}
	}
	
	void upd(int rt, int t1, int t2, int l, int r, int val) {
		if(l > r) return;
		else if(t1 <= l && t2 >= r) {
			st[rt].mn += val;
			st[rt].lz += val;
		} else {
			push(rt);
			int mid = (t1 + t2)/2;
			upd(2*rt, t1, mid, l, r, val);
			upd(2*rt+1, mid+1, t2, l, r, val);
		}
	}
};
