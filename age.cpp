#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct tree {
	array<int, 2> lv, slv;
};

tree combine(tree x, tree y) {
	tree ans;

	
	vector<array<int, 2>> v(4);
	v[0]=x.lv;
	v[1]=y.lv;
	v[2]=x.slv;
	v[3]=y.lv;

	sort(v.rbegin(), v.rend());

	for(int i = 4-1; i>0; --i) {
		if(v[i][0] == v[i-1][0])
			v[i-1][1]+=v[i][1];
	}

	ans.lv=v[0];
	ans.slv=v[1];
	return ans;
}

const int mxN=2e5+5;
tree st[4*mxN];
int a[mxN];

void build(int root, int t1, int t2) { 
	if(t1==t2) {
		st[root]={array<int, 2>{a[t1],1}, array<int,2>{-1,0}};
	} else {
		int mid=(t1+t2)/2;
		build(2*root,t1,mid);
		build(2*root+1,mid+1,t2);
		st[root]=combine(st[2*root], st[2*root+1]);
	}
}

tree qry(int v, int t1, int t2, int l, int r) {
	if(l > t2 || r < t1)
		return {array<int, 2>{-1,0}, array<int,2>{-1,0}};
	if(l<=t1&&r>=t2) {
		return st[v];
	}
	int mid = (t1+t2)/2;
	return combine(qry(2*v,t1,mid,l,r),qry(2*v+1,mid+1,t2,l,r));
}

void upd(int v, int t1, int t2, int p, int val) {
	if(t1==t2) {
		st[v]={array<int, 2>{val,1}, array<int,2>{-1,0}};
	} else {
		int mid=(t1+t2)/2;
		if(p <= mid)
			upd(2*v,t1,mid,p,val);
		else
			upd(2*v+1,mid+1,t2,p,val);
		st[v]=combine(st[2*v],st[2*v+1]);
	}
}


void solve_test_case() {
	int N;
	cin >> N;
	int Q;
	cin >> Q;
	for(int i = 0; i < N; ++i)
		cin >> a[i];

	build(1,0,N-1);
	//return;
	while(Q--) {
		int T;
		cin >> T;
		if(T==1) {
			int p, x;
			cin >> p >> x;
			--p;
			upd(1,0,N-1,p,x);
		} else if(T==2) {
			int L, R;
			cin >> L >> R;

			--L, --R;
			tree ans = qry(1,0,N-1,L,R);
			cout << ans.slv[1] << "\n";
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	//cin >> T;


	while(T--) {
		solve_test_case();
	}
}
