#include<bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
using ll = long long;
ll ft[mxN];
int sum(int n){
    int s=0;
    n++;
    while(n>0){
        s+=ft[n];
        n -= (n & (-n));
    }
    return s;
}

void pointUpdate(int i, int k, int size) {
    i++;
    while(i<=size){
        ft[i]+=k;
        i += (i & (-i));
    }
}
void fill(vector<int> &v){
    int n = v.size();
    for(int i =1; i <= n; i++){
        ft[i]=0;
    }
    for(int i=0;i < n; i++){
        pointUpdate(i, v[i], n);
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &e: v) cin >> e;
    fill(v);
    cout << sum(3);
}
