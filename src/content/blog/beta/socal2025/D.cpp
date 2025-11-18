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

    set<int> s;
    int n; cin >> n;
    vector<set<int>> adj(10005);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        s.insert(a);
        s.insert(b);
        adj[a].insert(b);
        adj[b].insert(a);
    }

    int closed = 0, open = 0;

    for (auto &one : s) {
        for (auto &two : adj[one]) {
            for (auto &three : adj[two]) {
                if (three == one) continue;
                if (adj[one].count(three)) {
                    closed++;
                } else {
                    open++;
                }
            }
        }
    }
    cout << closed / 6 << " " << open / 2 << endl;


}
