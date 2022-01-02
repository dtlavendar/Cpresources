struct Hashing {
	using T = long long;

	T mod = 998244353;
	T base = 51;
	int N;
	std::vector<T> hash_array;
	std::vector<T> prefix_hash_store;

	Hashing(const std::string &s) {
		N = s.size();
		hash_array.resize(N);
		prefix_hash_store.resize(N);

		hash_array[0] = s[0];
		for(int i = 1; i < N; i++) {
			hash_array[i] = (hash_array[i - 1] * base + s[i]) % mod;
		}

		prefix_hash_store[0] = 1;
		for(int i = 1; i < N; i++) {
			prefix_hash_store[i] = prefix_hash_store[i - 1] * base % mod;
		}
	}

	T query(int l, int r) {
		// [l, r]
		if(l == 0)
			return hash_array[r];
		else
			return (hash_array[r] - hash_array[l - 1]*prefix_hash_store[r-l+1]) % mod;
	}
};