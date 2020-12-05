#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define pb push_back
#define vii vector<pair<int, int>>
#define vi vector<int>
#define vt vector
#define ss(a) int(a.size())
#define ls second
#define fs first
#define vl vector<ll>
#define readarr(n) for(auto&xabv:n)cin>>xabv
const int inf = 1000000000;
const int mod = inf+7;
 
 
template<typename... T>
void write(T&... args){
	((cout << args << " "), ...);
}
#define sum accumulate
#define allsum(a) sum(a.begin(), a.end(), 0)
void printArr(vector<int> &s) {
	for(auto&x:s){
		write(x);
	}
	cout << '\n';
}
int main() {
 
	int n;
	cin >> n;
	while(n--) {
		ll y, x;
		cin >> y >> x;
		// y is the row, x is the column
		ll ans = max(y,x);
		ll ans2=(y-x)*ll(pow(-1, ans))+ans*ans-ans+1;
		cout << ans2 << '\n';
	}
 
	
}
