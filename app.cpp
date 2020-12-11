#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    for(auto &e: V) cin >> e;

    vector<int> dp(N);
    dp[0]=0;
    dp[1]=abs(V[0]-V[1]);
    for(int i =2; i < N; ++i){
        dp[i]=abs(V[i]-min(dp[i-1] + V[i-1], dp[i-2] + V[i-2]));
    }
    cout << dp[N-1];
}