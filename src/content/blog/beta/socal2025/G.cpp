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

    int result = 0;
    int n;
    cin >> n;
    int prev = -1;
    rep(i, 0, n) {
        int x;
        cin >> x;
        int larger = max(prev, x), smaller = min(prev, x);

        if (prev != -1)
            result += larger * larger - smaller * smaller;
        prev = x;

        result += 4 * x * x;

        if (i == 0) {
            result += x * x;
        }
        if (i == n - 1) {
            result += x * x;
        }
    }

    cout << result << endl;
}
