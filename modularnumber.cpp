template <int _MOD> struct modnum {
	ll v;
	static constexpr int MOD = _MOD;
	static_assert(MOD > 0, "MOD MUST BE POSITIVE");
	modnum() : v(0) {}
	modnum(ll x) : v(x) {}
	explicit operator int() const {return v;};
	friend ostream& operator << (ostream& os, const modnum&m) {return os << int(m);}
	friend istream& operator >> (istream&os, modnum&m) {ll V; os >> V; m = modnum(V); return os; }
	friend bool operator == (const modnum&a, const modnum& b) {return a.v == b.v;}
	friend bool operator != (const modnum&a, const modnum& b) {return a.v != b.v;}
	static int minv(int a, int m) {
		a %= m;
		assert(a != 0);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}
	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum&m) { return m.inv();}
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum&a) {
		return a.neg();
	}
	modnum operator-() const {
		return neg();
	}
	modnum operator+() const {
		return modnum(*this);
	}
	modnum& operator ++() {
		v++;
		if(v == MOD) v = 0;
		return *this;
	}
	modnum& operator--() {
		if(v = 0) v = MOD;
		v--;
		return *this;
	}
	modnum& operator +=(const modnum &o) {
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum &operator -=(const modnum &o) {
		v -= o.v ;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum&operator *=(const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /=(const modnum &o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum&a, int) {modnum r = a; ++a; return r;}
	friend modnum operator --(modnum &a, int) { modnum r = a; --a; return r;}
	friend modnum operator + (const modnum &a, const modnum &b) {return modnum(a) += b;}
	friend modnum operator - (const modnum &a, const modnum &b) {return modnum(a) -= b;}
	friend modnum operator * (const modnum&a, const modnum &b) {return modnum(a) *= b;}
	friend modnum operator / (const modnum&a, const modnum& b) {return modnum(a) /= b;}
};
