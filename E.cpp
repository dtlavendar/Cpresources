#include <vector>
#include <iostream>

#include <cstring>
#include <algorithm>
#include <string>
#include <ostream>
#include <map>
#include <set>
#include <utility>

using namespace std;
using namespace std;
using ll = long long;
using vi = vector<int>;

string T, S;
const int mxN=11, mxk=100, inf=1061109567;
int N, M, K;

int dp[1001][1001];
void solve_test_case() {
    cerr << "HI\n";
    cin >> N >> M >> K;
    K--;
    dp[K][0] = 1;


    cerr << "HI\n";
    vector<pair<int, char>> queries(M);
    for(int i = 0; i < M; i++) {
        int dist; char type;
        cin >> dist >> type;
        queries[i] = {dist, type};
    }
    cerr << "HI\n";

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(dp[j][i] > 0) {
                if(queries[i].second == '0') {
                    int pos = (j + queries[i].first);
                    if(pos > N)
                        pos = pos % N;
                    dp[pos][i+1] = max(dp[pos][i+1], dp[j][i]);
                }
                if(queries[i].second == '1') {
                    int pos = (j - queries[i].first);
                    if(pos < 0)
                        pos = pos + N;

                    dp[pos][i+1] = max(dp[pos][i+1], dp[j][i]);
                } else if(queries[i].second == '?') {
                    int pos = (j - queries[i].first);
                    if(pos < 0)
                        pos = pos + N;
                    dp[pos][i+1] = max(dp[pos][i+1], dp[j][i]);
                    pos = (j + queries[i].first);
                    if(pos > N)
                        pos = pos % N;
                    dp[pos][i+1] = max(dp[pos][i+1], dp[j][i]);
                }
            }
        }
    }

    vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(dp[i][M] > 0) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for(int i : ans)
        cout << i << " ";

    cout << "\n";

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;


	while(T--) {
		solve_test_case();
	}
}

