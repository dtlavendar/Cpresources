ll modpow(ll x, ll y, ll mod) {
	ll result = 1;

	while(y) {
		if(y&1)
			result = ((result % mod) * (x%mod)) % mod;
		x = (x*x) % mod;
		y >>= 1;
	}
	return result;
}

bool miller_rabin(ll n) {
	if(n < 2)
		return false;

	for(int64_t pr : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
		if(n % pr == 0)
			return n == pr;


	int64_t r = __builtin_ctz(n);
	int64_t d = (n-1) >> r;

	for(int64_t pr : {2, 3, 61}) {
		ll res = modpow(pr % n, d, n);
		if(res == 1 || res == n - 1) continue;

		while(d != n - 1) {
			res *= res;
			res %= n;
			d >>= 1;

			if(res == 1)
				return false;
			else if(res == n-1)
				break;
		}

		if(res != n - 1)
			return false;
	}
	return true;
}
