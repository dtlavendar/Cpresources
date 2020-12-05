#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
	ll n;
	cin >> n;
	ll s=0;
	ll ans = n*(n+1)/2;
	vector<int> a(n-1);
	for(int i =0; i < n; i++){
		cin >> a[i];
		s+=a[i];
	}
	cout << ans-s;	
	
}
