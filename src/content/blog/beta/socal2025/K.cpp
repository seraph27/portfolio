#pragma GCC optimize("Ofast")

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

const int inf = 1e9;

struct Tree {
    typedef int T;
    static constexpr T unit = LLONG_MIN;
    T f(T a, T b) {
        return max(a, b);
    }
    vc<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}

    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2] + 1);
    }

    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e/= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

// struct Node {
//     Node *l = 0, *r = 0;
//     int lo, hi, mset = inf, madd = 0, val = -inf;
//     Node(int lo, int hi) : lo(lo), hi(hi) {}
//     Node(vi &v, int lo, int hi) : lo(lo), hi(hi) {
//         if (lo + 1 < hi) {
//             int mid = lo + (hi - lo) / 2;
//             l = new Node(v, lo, mid); r = new Node(v, mid, hi);
//             val = max(l->val, r->val);
//         }
//         else val = v[lo];
//     }
//
//     int query(int L, int R) {
//         if (R <= lo || hi <= L) return -inf;
//         if (L <= lo && hi <= R) return val;
//         push();
//         return max(l->query(L, R), r->query(L, R));
//     }
//
//     void set(int L, int R, int x) {
//         if (R <= lo || hi <= L) return;
//         if (L <= lo && hi <= R) mset = val = x, madd = 0;
//         else {
//             push(), l->set(L, R, x), r->set(L, R, x);
//             val = max(l->val, r->val);
//         }
//     }
//
//     void add(int L, int R, int x) {
//         if (R <= lo || hi <= L) return;
//         if (L <= lo && hi <= R) {
//             if (mset != inf) mset += x;
//             else madd += x;
//             val += x;
//         }
//         else {
//             push(), l->add(L, R, x), r->add(L, R, x);
//             val = max(l->val, r->val);
//         }
//     }
//
//     void push() {
//         if (!l) {
//             int mid = lo + (hi - lo) / 2;
//             l = new Node(lo, mid); r = new Node(mid, hi);
//         }
//         if (mset != inf)
//             l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
//         else if (madd)
//             l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
//     }
// };

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vc<vc<pii>> neighbors(n);
    rep(i, 0, n) {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        neighbors[u].pb({v, d});
        neighbors[v].pb({u, d});
    }

    vi prev(n, -1);
    int cycleEnd = -1;

    function<void(int, int)> dfs;
    dfs = [&](int cur, int par) {
        if (cycleEnd != -1) return;

        // cout << "dfs on " << cur << " " << par << endl;

        if (prev[cur] != -1) {
            // cout << " FOUND! " << cur << " " << par << " " << prev[cur] << endl;
            cycleEnd = cur;
            return;
        }
        prev[cur] = par;

        for (auto &neighbor : neighbors[cur]) {
            if (neighbor.fs == par) continue;
            if (cycleEnd != -1) return;

            dfs(neighbor.fs, cur);
        }
    };
    dfs(0, -1);

    assert(cycleEnd != -1);
    vi cycleList = {cycleEnd};
    int cur = prev[cycleEnd];
    while (cur != cycleEnd) {
        cycleList.pb(cur);
        cur = prev[cur];
    }

    for (int num : cycleList) {
        cout << num << ' ';
    }
    cout << endl;

    int numTrees = sz(cycleList);
    vi subtreeDepths(numTrees, 0);
    vi distToRoot(n, 0), rootId(n);
    rep(i, 0, numTrees) {
        // cout << i << " BEGIN DFS " << endl;
        function<void(int, int, int)> dfs;
        dfs = [&](int cur, int par, int dist) {
            // cout << "DFSD ING " << cur << " " << par << " " << dist << endl;
            rootId[cur] = cycleList[i];
            distToRoot[cur] = dist;

            subtreeDepths[i] = max(subtreeDepths[i], dist);

            for (auto &neighbor : neighbors[cur]) {
                // cout << "neigh : " << neighbor.fs << " " << cycleList[(i + 1) % numTrees] << " " << cycleList[(i - 1 + n) % numTrees] << endl;
                if (neighbor.fs == cycleList[(i + 1) % numTrees] || neighbor.fs == cycleList[(i - 1 + numTrees) % numTrees] || neighbor.fs == par) {
                    continue;
                }
                dfs(neighbor.fs, cur, dist + neighbor.sd);
            }
        };
        dfs(cycleList[i], -1, 0);
    }

    // cycleDists[i] is dist from cycleList[i] to cycleList[(i + 1) % numTrees]
    vi cycleDists(numTrees, 0);

    int totalAroundCycle = 0;
    rep(i, 0, numTrees) {
        int node = cycleList[i];
        for (auto &neighbor : neighbors[node]) {
            if (neighbor.fs == cycleList[(i + 1) % numTrees]) {
                cycleDists[i] = neighbor.sd;
                break;
            }
        }
        totalAroundCycle += cycleDists[i];
    }

    Tree cwDist(numTrees), ccwDist(numTrees);
    int cwPrefix = 0;
    rep(i, 0, numTrees) {
        cout << "sub depth: " << subtreeDepths[i] << endl;
        cwDist.update(i, cwPrefix + subtreeDepths[i]);
        ccwDist.update(i, totalAroundCycle - cwPrefix + subtreeDepths[i]);
        cwPrefix += cycleDists[i];

        // cout << i << " node " << cycleList[i] << " cycle dist " <<cycleDists[i] << endl;
    }

    // cout << "initial values are" << endl;
    // rep(j, 0, numTrees) {
    //     cout << j << " cw: " << cwDist.query(j, j + 1) << " ccw " <<ccwDist.query(j, j + 1) << endl;
    // }

    int cwOffset = 0, ccwOffset = 0;

    int x = 0;
    vi maxDists(n, 0);
    rep(i, 0, numTrees) {
        cout << "offsets " << cwOffset << " " << ccwOffset << endl;

        cwDist.update(i,  subtreeDepths[i] -cwOffset);
        ccwDist.update(i, subtreeDepths[i] -ccwOffset);

        // cout << "CCW: " << ccwOffset << endl;
        // cout << "I VAL : " << ccwDist.query(i, i + 1) << endl;
        //
        // cout << "before " << i << " values are" << endl;
        // rep(j, 0, numTrees) {
        //     cout << j << " cw: " << (cwDist.query(j, j + 1) + cwOffset) << " ccw " << (ccwDist.query(j, j + 1) + ccwOffset) << endl;
        // }

        while (cwDist.query(x, x + 1) + cwOffset <= ccwDist.query(x, x + 1) + ccwOffset) {
            // cout << "FUCK YOU " << x << " " << cwDist.query(x, x + 1) << " " << ccwDist.query(x, x + 1)<< " " << endl;
            x = (x + 1) % numTrees;
        }
        x = (x + numTrees - 1) % numTrees;

        int mMax = 0;
        if (i <= x) {
            mMax = max(mMax, cwDist.query(i, x + 1) + cwOffset);
        } else {
            mMax = max(mMax, cwDist.query(0, x + 1) + cwOffset);
            mMax = max(mMax, cwDist.query(i, numTrees) + cwOffset);
        }
        if (i <= x) {
            mMax = max(mMax, ccwDist.query(0, i) + ccwOffset);
            mMax = max(mMax, ccwDist.query(x + 1, numTrees) + ccwOffset);
        } else {
            mMax = max(mMax, ccwDist.query(x + 1, i) + ccwOffset);
        }

        maxDists[cycleList[i]] = mMax;

        // cout << "max dist: " << i << " " << x << " " << cycleList[i] << " " << mMax << endl;

        cwOffset -= cycleDists[i];
        ccwOffset += cycleDists[i];

        if (cwOffset >= totalAroundCycle) {
            cwOffset -= totalAroundCycle;
        }
        if (cwOffset < 0) {
            cwOffset += totalAroundCycle;
        }

        if (ccwOffset >= totalAroundCycle) {
            ccwOffset -= totalAroundCycle;
        }
        if (ccwOffset < 0) {
            ccwOffset += totalAroundCycle;
        }

        cwDist.update(i, totalAroundCycle + subtreeDepths[i] - cycleDists[i] - cwOffset);
        ccwDist.update(i,cycleDists[i] + subtreeDepths[i] - ccwOffset);
    }

    rep(i, 0, n) {
        int res = distToRoot[i] + maxDists[rootId[i]];

        cout << res << ' ';
    }
    cout << endl;
}
