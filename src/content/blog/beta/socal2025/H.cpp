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

    int m, n, t;
    cin >> m >> n >> t;
    map<int, int> counts;
    counts[t / 2] = 0;
    counts[0] = 0;

    rep(i, 0, m) {
        int x;
        cin >> x;
        if (counts.count(x)) {
            counts[x]++;
        } else {
            counts[x] = 1;
        }
    }

    int extra = n - m;
    int already = 0, best = 0;

    set<int> seen;

    for (auto &cnt : counts) {
        if (seen.count(cnt.fs)) continue;
        int counterpart = t - cnt.fs;
        seen.insert(counterpart);
        if (cnt.fs < 0 || counterpart < 0) continue;
        int counterCount = counts.count(counterpart) ? counts[counterpart] : 0;

        if (cnt.fs == counterpart) {
            int contrib = (cnt.sd * (cnt.sd - 1)) / 2;
            already += contrib;
            int maxedOut = cnt.sd + extra;
            best = max(best, (maxedOut * (maxedOut - 1)) / 2 - contrib);
            continue;
        }

        already += cnt.sd * counterCount;

        int larger = max(counterCount, cnt.sd), smaller = min(counterCount, cnt.sd);
        int ogLarger = larger, ogSmaller = smaller;
        int myExtra = extra;
        if (larger - smaller >= myExtra) {
            smaller += myExtra;
        } else {
            myExtra -= (larger - smaller);
            smaller = larger;
            smaller += myExtra / 2;
            larger += (myExtra + 1) / 2;
        }
        best = max(best, smaller * larger - ogSmaller * ogLarger);

        // cout << cnt.fs << " " << cnt.sd << " " << best << endl;
    }

    cout << (already + best) << endl;
}
