struct min_t {
    long long val;

    min_t() : val(9e18) {}
    min_t(long long _val) : val(_val) {}
    min_t(long long x, long long y) {
        val = min(x, y);
    }
    min_t(const min_t &x) {
        *this = x;
    }

    min_t(const min_t &x, const min_t &y) {
        combine(x, y);
    }

    void combine(const min_t &x, const min_t &y) {
        val = min(x.val, y.val);
    }

    min_t combine(const min_t &x, long long y) {
        val = min(x.val, y);
    }

    void op(const min_t &x) {
        *this = min_t(x, *this);
    }
};
