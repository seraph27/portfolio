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

    vc<vc<string>> arr(10, vc<string>(10));
    rep(i, 0, 10) rep(j, 0, 10) cin >> arr[i][j];

    reverse(all(arr));

    rep(i, 0, 10) {
        if (i % 2 == 1) {
            reverse(all(arr[i]));
        }
    }

    // row then col
    priority_queue<pair<int, pii>, vc<pair<int, pii>>, greater<>> pq;
    pq.push({0, {0, 0}});
    vc<vi> seen(10, vi(10, 0));
    while (!pq.empty()) {
        auto entry = pq.top();
        pq.pop();

        pii cur = entry.sd;

        // cout << "at square " << cur.fs << " " << cur.sd << endl;

        if (cur.fs >= 10 || (cur.fs == 9 && cur.sd == 9)) {
            cout << "Win in " << entry.fs << endl;
            exit(0);
        }

        if (seen[cur.fs][cur.sd]) continue;
        seen[cur.fs][cur.sd] = 1;

        // cout << "first time " << cur.fs << " " << cur.sd << endl;
        // cout << entry.fs << endl;

        string s = arr[cur.fs][cur.sd];
        if (s[0] == 'S') continue;

        if (s[0] == 'L') {
            pii target;
            if (sz(s) == 4) {
                cout << "Win in " << entry.fs << endl;
                exit(0);
            }

            if (sz(s) == 2) {
                target = {0, s[1] - '0' - 1};
            } else {
                target = {s[1] - '0', s[2] - '0' - 1};
                if (s[2] == '0') {
                    target = {s[1] - '0' - 1, 9};
                }
            }
            // cout << "climbing ladder to " << target.fs << " " << target.sd << endl;
            // cout << entry.fs << endl;
            pq.push({entry.fs, target});
            continue;
        }

        pii tmp = cur;
        rep(i, 0, 6) {
            tmp.sd++;
            if (tmp.sd >= 10) {
                tmp.sd -= 10;
                tmp.fs++;
            }
            // cout << cur.fs << " " << cur.sd << endl;
            // cout << "move to " << tmp.fs << " " << tmp.sd << endl;
            pq.push({entry.fs + 1, tmp});
        }
    }

    cout << "Snakes awaiting" << endl;
}
