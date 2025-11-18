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

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;

    multiset<int> endCounts;
    // first is x-coord, second is x-coord of end
    vc<pii> starts;
    int pairs = 0;

    rep(i, 0, n) {
        int x, r;
        cin >> x >> r;
        int start = x - r, end = x + r;
        starts.pb({start, end});
    }
    sort(all(starts));
    rep(i, 0, n) {
        // process pending ends, pairing together as needed
        while (!endCounts.empty() && *endCounts.begin() < starts[i].fs) {
            if (sz(endCounts) == 1) {
                endCounts.erase(endCounts.begin());
            } else {
                endCounts.erase(endCounts.begin());
                endCounts.erase(endCounts.begin());
                pairs++;
            }
        }

        // process this start
        endCounts.insert(starts[i].sd);
    }

    // end parsing
    while (!endCounts.empty()) {
        if (sz(endCounts) == 1) {
            endCounts.erase(endCounts.begin());
        } else {
            endCounts.erase(endCounts.begin());
            endCounts.erase(endCounts.begin());
            pairs++;
        }
    }

    cout << (n - 2 * pairs) << endl;

    // vector<ar<int, 3>> vi;
    // int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     int start, r; cin >> start >> r;
    //     vi.pb({start - r, 1, 2 * i});
    //     vi.pb({start + r, -1, 2 * i + 1});
    // }
    //
    // sort(all(vi), [&](auto &a, auto & b) {
    //     if (a[0] == b[0]) {return a[1] > b[1];}
    //     return a[0] < b[0];
    // });
    //
    // int curr = 0;
    // vector<int> ban(2 * n + 5, false);
    // for (int i = 0; i < sz(vi); i++) {
    //     if (ban[i]) continue;
    //     auto &[fi, se, three] = vi[i];
    //     if (se == 1) {
    //         curr+=se;
    //         continue;
    //     }
    //     if (curr >= 2) {
    //         curr--;
    //     } else {
    //         ans++;
    //         continue;
    //     }
    //     curr+=se;
    //     ban[three] = true;
    // }
    // cout << ans << endl;
}
