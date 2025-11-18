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
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    double total = 0;
    double extras = 0;
    rep(i, 0, n) {
        string s;
        cin >> s;

        int numericScore = 4 - (s[0] - 'A');
        total += numericScore;

        if (s[0] <= 'C') {
            extras += ('3' - s[1]) * 0.025;
        }
    }

    cout << fixed << setprecision(9) << ((total / n) + extras) << endl;
}
