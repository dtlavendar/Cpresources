#include <iostream>
#include <vector>
using namespace std;

template<int _S>
struct modint {
    using ll = long long;
    ll v;
    static constexpr int MOD = _S;
    static_assert(MOD > 0, "MOD HAS TO BE G than 0");
    modint() : v(0) {}
    modint(ll V) : v(V) {}
    
    ll gcd(ll x, ll y) {
        return y ? gcd(y, x % y) : x;
    }
    ll minv() {
        int m = MOD;
        ll x = v;
        if(gcd(MOD, v) == 1) {
            return x=((x%m+m)%m);
        } else return v;
    }
    explicit operator int() const {return v;}
    friend ostream& operator << (ostream& os, const modint&m) {
        return os << int(m);
    }
    friend istream& operator >> (istream &os, const modint&m) {
        ll V; os >> V; 
        m = modint(V);
        return os;
    }
    friend bool operator != (const modint<MOD>&a, const modint &b) {return a.v != b.v;}
    friend bool operator == (const modint<MOD> &a, const modint<MOD>&b) {return a.v == b.v;};
    modint &operator =(ll a) {
        v=a;
        return *this;
    }
    modint &operator -=(const modint<MOD>&a) {
        v -= a.v;
        if(v < 0) v += MOD;
        return *this;
    }
    modint &operator +=(const modint<MOD>&a) {
        v += a.v;
        v %= MOD;
        return *this;
    }
    modint &operator *=(const modint<MOD>&a) {
        v = ((v%MOD)*(a.v%MOD)) % MOD;
        return *this;
    }
    modint &operator /=(const modint<MOD> &a) {
        v = ((v%MOD)*(a.minv()%MOD))%MOD;
    }
    template<class T>
    modint &operator -=(T a) {
        v -= a;
        if(v < 0) v += MOD;
        return *this;
    }
    template<class T>
    modint &operator +=(T a) {
        v += a;
        v %= MOD;
        return *this;
    }
    template<class T>
    modint &operator *=(T a) {
        v = ((v%MOD)*(a%MOD)) % MOD;
        return *this;
    }
    template<class T>
    modint &operator /=(T a) {
        v = ((v%MOD)/(a%MOD))%MOD;
    }
    friend modint operator+(const modint<MOD> &a, ll b) {
        modint<MOD> res;
        res.v=a.v;
        res += b;
        return res;
    }
    friend modint operator-(const modint<MOD> &a, ll b) {
        modint<MOD> res;
        res.v=a.v;
        res-=b;
        return res;
    }
    friend modint operator*(const modint<MOD> &a, ll b) {
        modint<MOD> res;
        res.v=a.v;
        res*=b;
        return res;
    }
    friend modint operator+(const modint<MOD> &a, const modint<MOD> &b) {
        modint<MOD> res;
        res.v=a.v;
        res+=b;
        return res;
    }
    friend modint operator-(const modint<MOD> &a, const modint<MOD> &b) {
        modint<MOD> res;
        res.v=a.v;
        res-=b;
        return res;
    }
    friend modint operator*(const modint<MOD> &a, const modint<MOD> &b) {
        modint<MOD> res;
        res.v=a.v;
        res*=b;
        return res;
    }
    
    
};

