#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define vc vector
#define fs first
#define sd second
#define ar array
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int a, b, p;
    cin >> a >> b >> p;
    //vc<vi> dp(a+1, vi(b+1));
    int o = min(a, b);
    vector<ar<int, 2>> dp(o + 1, ar<int, 2>());
    // rep(i, 0, a+1) dp[i][0] = 0;
    // rep(i, 0, b+1) dp[0][i] = 0;
    // dp[1][1] = 1;
    // rep(i, 1, a+1) {
    //     rep(j, 1, b+1) {
    //         if (i == 1 && j == 1) continue;
    //
    //         dp[i][j] = (dp[i-1][j] + dp[i][j-1] + dp[i-1][j] * (i + j - 2)) % p;
    //     }
    // }
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 0; i < o; i++) for (int k = 0; k < 2; k++) {
        (dp[i + 1][1] += dp[i][0]) %= p;
        (dp[i + 1][1] += dp[i][1]) %= p;
        (dp[i + 1][0] += dp[i][0]) %= p;
        (dp[i + 1][0] += dp[i][1]) %= p;
    }

    cout << (dp[o][0]) % p << endl;
}
