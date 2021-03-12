template<class T> struct rangeSum {
	vector<T> prefixSums;
	void init(vector<T> &a) {
		prefixSums = a;
		partial_sum(prefixSums.begin(), prefixSums.end(), prefixSums.begin());
	}
	T query(int l, int r) {
		assert(l >= 0 && r < int(prefixSums.size()));
		return l == 0 ? prefixSums[r] : prefixSums[r] - prefixSums[l-1];
	}
	void add(int l, int r, T val) {
		prefixSums[r] += val;
		prefixSums[l] -= val;
	}
};
