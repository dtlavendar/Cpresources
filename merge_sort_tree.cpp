struct merge_sort_tree {
	vector<vector<int>> data;
	vector<int> a;
	merge_sort_tree(int T, vector<int> avx) {
		data.resize(T << 1 | 1);
		// apparently if doesn't work if T is a power of 2, but honestly i have no idea how true / false this is
		a = avx;
	}
	
	vector<int> combine(vector<int> a, vector<int> b) {
		vector<int> ans;
		int l = 0, r = 0;
		
		while(l < int(a.size()) && r < int(b.size())) {
			if(a[l] < b[r]) {
				ans.push_back(a[l]);
				++l;
			} else {
				ans.push_back(b[r]);
				++r;
			}
		}
		
		while(l < int(a.size())) ans.push_back(a[l]);
		
		while(r < int(b.size())) ans.push_back(b[r]);
		
		return ans;
	}
	
	void build(int ver, int t1, int t2) {
		if(t1 == t2) {
			data[ver] = vector<int> {a[ver]};
		} else {
			int mid = (t1+t2)>>1;
			build(ver << 1, t1, mid);
			build(ver << 1 | 1, mid + 1, t2);
			data[ver] = combine(data[ver << 1], data[ver << 1 | 1]);
		}
	}
	
	int query(int ver, int t1, int t2, int l, int r, int x) {
		if(l > t2 || r < t1) return 0;
		
		if(l > r) return 0;
		if(t1 > t2) return 0;
		
		
		if(l <= t1 && r >= t2) {
			int b = lower_bound(data[ver].begin(), data[ver].end(), x) - data[ver].begin();
			int c = upper_bound(data[ver].begin(), data[ver].end(), x) - data[ver].begin();
			return (c - b);
		} else {
			int mid = (t1 + t2) >> 1;
			return query(ver << 1, t1, mid, l, r, x) + query(ver << 1 | 1, mid + 1, t2, l, r, x);
		}
	}
};
