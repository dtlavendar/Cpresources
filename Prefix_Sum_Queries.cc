//#include <vector>
struct prefix_sum_queries {
	using T = long long;
	std::vector<T> prefix;

	int N;

	prefix_sum_queries(std::vector<T> &l) {
		N = l.size();
		prefix = std::vector<T> (l.begin(), l.end());
		for(int i = 1; i < N; i++)
			prefix[i] += prefix[i - 1];
	}

	T query(int l, int r) {
		// [l, r)
		return l == 0 ? prefix[r - 1] : prefix[r - 1] - prefix[l - 1];
	}
};