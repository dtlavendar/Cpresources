#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
	string s;
	cin >> s;
	ll ans  =1;
	ll c = 1;
	char cs= s[0];
	for(int i =1; i<s.size();  i++){
		if(s[i]==cs) {
			++c;
			ans=max(c,ans);
		} else {
			cs=s[i];
			c=1;
		}
	}
	cout <<ans;
}
