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

    int t;
    cin >> t;
    while (t--) {
        pii a, b, c;
        cin >> a.fs >> a.sd >> b.fs >> b.sd >> c.fs >> c.sd;

        int aLen = a.fs * a.fs + a.sd * a.sd;
        int bLen = (b.fs - a.fs) * (b.fs - a.fs) + (b.sd - a.sd) * (b.sd - a.sd);
        int cLen = (c.fs - a.fs) * (c.fs - a.fs) + (c.sd - a.sd) * (c.sd - a.sd);

        bool possible = true;
        if (bLen > aLen || cLen > aLen) {
            possible = false;
        } else if (bLen < aLen && cLen < aLen) {
            possible = true;
        } else {
            // are A and B on same line, or A and C on same line, AND is equal to length?
            if (((b.fs == a.fs * 2 && b.sd == a.sd * 2) && aLen == bLen) || ((c.fs == a.fs * 2 && c.sd == a.sd * 2) && aLen == cLen)) {
                possible = false;
            } else {
                if (aLen == cLen && aLen == bLen) {
                    // are any 2 segments intersecting?
                    if ((b.fs == 0 && b.sd == 0) || (c.fs == 0 && c.sd == 0) || (b.fs == c.fs && b.sd == c.sd)) {
                        possible = true;
                    } else {
                        possible = false;
                    }
                } else {
                    possible = true;
                }
            }
        }

        cout << (possible ? "YES" : "NO") << endl;
    }
}
