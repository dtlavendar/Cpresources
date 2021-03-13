struct fentree {
	int N;
	vector<ll> q;
	fentree(int _S) {
		N = _S;
		q.resize(N+1);
	}

	void add(int idx, ll val) {
		for(++idx; idx <= N; idx += idx & -idx)
			q[idx] += val;
	}
	void rangeAdd(int l, int r, ll val) {
		add(r+1, -val);
		add(l, val);
	}
	ll get(int idx) {
		ll sum = 0;
		for(++idx; idx > 0; idx -= idx & -idx)
			sum += q[idx];
		return sum;
	}
	ll rangeQuery(int l, int r) {
		if(l == 0) {
			return get(r);
		} else {
			return get(r) - get(l-1);
		}
	}
};
