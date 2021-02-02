struct pt {
	ll x, y;
	pt() : x(0), y(0) {}
	pt(ll a, ll b) : x(a), y(b) {}
	pt(const pt& a) : x(a.x), y(a.y) {}
	pll slope(const pt& a) {
		ll slp;
		slp = a.y - this->y;
		slp /= (a.x - this->x);
		ll b;
		b = this->y - (slp * this->x);
		return make_pair(slp, b);
	}
	ll product(const pt &a) {
		ll s =( this->x * (a.y) ) - (this->y * a.x);
		return s;
	}
	pt operator+(const pt &a) {
		pt t(a);
		t.x += this->x;
		t.y += this->y;
		return t;
	}
	pt operator-(const pt &a) {
		pt t(a);
		t.x -= this->x;
		t.y -= this->y;
		return t;
	}
	pt operator*(const pt &a) {
		pt t(a);
		t.x *= this->x;
		t.y *= this->y;
		return t;
	}
	pt operator/(const pt &a) {
		pt t(a);
		t.x /= this->x;
		t.y /= this->y;
		return t;
	}
};
