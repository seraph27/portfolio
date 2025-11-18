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

double manh(double x1, double x2, double y1, double y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

pair<double, double> umbrella(double x, double y) {
    return {sqrt(2) * -y, sqrt(2) * x};
}

void solve() {
    int x1, y1, x2, y2;
    char d1, d2;
    cin >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;

    if (d1 == d2) {
        if (d1 == 'N') {
            double ret = manh(x1, x2, y1, y2);
            pair<double, double> a1 = umbrella(x1, y1), a2 = umbrella(x2, y2);
            double low = min(min(manh(x1, a1.fs / sqrt(2), y1, -a1.fs / sqrt(2)) + abs(a1.fs - a2.fs) + manh(x2, a2.fs / sqrt(2), y2, -a2.fs / sqrt(2)),
                                    manh(x1, a1.fs / sqrt(2), y1, -a1.fs / sqrt(2)) + abs(a1.fs - a2.sd) + manh(x2, a2.sd / sqrt(2), y2, -a2.sd / sqrt(2))),
                             min(manh(x1, a1.sd / sqrt(2), y1, -a1.sd / sqrt(2)) + abs(a1.sd - a2.fs) + manh(x2, a2.fs / sqrt(2), y2, -a2.fs / sqrt(2)),
                                    manh(x1, a1.sd / sqrt(2), y1, -a1.sd / sqrt(2)) + abs(a1.sd - a2.sd) + manh(x2, a2.sd / sqrt(2), y2, -a2.sd / sqrt(2))));
            ret = min(ret, low);
            cout << setprecision(16) << ret << endl;
        } else {
            cout << setprecision(16) << manh(x1, x2, y1, y2) << endl;
        }
        return;
    } else if (d1 == 'N') {
        swap(x1, x2);
        swap(y1, y2);
        swap(d1, d2);
    }

    pair<double, double> a1 = umbrella(x2, y2);
    double ret = manh(x1, a1.fs, y1, 0) + x2 + y2;
    ret = min(ret, manh(x1, a1.sd, y1, 0) + x2 + y2);
    ret = min(ret, manh(ceil(x1 / sqrt(2)), x2, -ceil(x1 / sqrt(2)), y2) + abs(y1) + abs(ceil(x1 / sqrt(2)) * sqrt(2) - x1));
    ret = min(ret, manh(floor(x1 / sqrt(2)), x2, -floor(x1 / sqrt(2)), y2) + abs(y1) + abs(floor(x1 / sqrt(2)) * sqrt(2) - x1));

    cout << setprecision(16) << ret << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int q;
    cin >> q;
    while (q--) solve();
}
