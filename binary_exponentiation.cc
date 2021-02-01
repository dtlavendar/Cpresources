ll bin_exp(ll x, ll y) {
    if (y == 0) {
        return 1LL;
    }
    ll ans = bin_exp(x, y / 2);
 
    if(y % 2 == 0) {
        return ((ans % mod) * (ans % mod)) % mod;
    } else if(y % 2 == 1) {
        return (((ans % mod) * (ans % mod)) % mod * (x % mod)) % mod;
    }
}
void solve()
{
	ll a, b;
    cin >> a >> b;
    
    ll ans = bin_exp(a, b);
    print(ans);
}
int main()
{
    fastio;
    // clock_t t = clock();
    int tc = 1;
    cin >> tc;
	while(tc--){
        solve();
	}    
}
/* stuff 
