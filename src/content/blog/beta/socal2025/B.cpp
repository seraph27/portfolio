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

vc<vc<char>> read_in() {
    vc<vc<char>> ret(3, vc<char>(3));
    string s;
    rep(i, 0, 3) {
        cin >> s;
        rep(j, 0, 3) {
            ret[i][j] = s[j];
        }
    }

    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    vc<vc<vc<char>>> cube(6, vc<vc<char>>(3, vc<char>(3, '?')));
        // 0 = front, 1 = R, 2 = rear, 3 = L, 4 = top, 5 = bottom
    vc<vc<char>> in = read_in();
    rep(i, 0, 3) rep(j, 0, 3) cube[0][i][j] = in[i][j];

    rep(i, 1, 4) {
        cout << "U" << endl; read_in(); cout << "D'" << endl;
        in = read_in();

        if (i != 2) {
            rep(j, 0, 3) cube[i][0][j] = in[0][j];
            rep(j, 0, 3) cube[i][2][j] = in[2][j];
        } else {
            rep(j, 0, 3) cube[i][2][2-j] = in[0][j];
            rep(j, 0, 3) cube[i][0][2-j] = in[2][j];
        }
    }

    // reset cube
    cout << "U" << endl; read_in(); cout << "D'" << endl; read_in();

    for (auto &i : {4, 2, 5, -1}) {
        cout << "L" << endl; read_in(); cout << "R'" << endl;
        in = read_in();

        if (i != -1) {
            rep(j, 0, 3) cube[i][j][0] = in[j][0];
            rep(j, 0, 3) cube[i][j][2] = in[j][2];
        }
    }

    // top
    cout << "U" << endl; read_in();
    cout << "R'" << endl; read_in();
    cout << "L" << endl;
    in = read_in();
    cube[4][2][1] = in[1][0];
    cube[4][0][1] = in[1][2];

    cout << "R" << endl; read_in();
    cout << "L'" << endl; read_in();
    cout << "U'" << endl; read_in();

    // right
    cout << "R" << endl; read_in();
    cout << "U" << endl; read_in();
    cout << "D'" << endl;
    in = read_in();
    cube[1][1][0] = in[0][1];
    cube[1][1][2] = in[2][1];

    cout << "U'" << endl; read_in();
    cout << "D" << endl; read_in();
    cout << "R'" << endl; read_in();

    // left
    cout << "L" << endl; read_in();
    cout << "U'" << endl; read_in();
    cout << "D" << endl;
    in = read_in();
    cube[3][1][0] = in[0][1];
    cube[3][1][2] = in[2][1];

    cout << "U" << endl; read_in();
    cout << "D'" << endl; read_in();
    cout << "L'" << endl; read_in();

    // bottom
    cout << "D" << endl; read_in();
    cout << "R" << endl; read_in();
    cout << "L'" << endl;
    in = read_in();
    cube[5][2][1] = in[1][0];
    cube[5][0][1] = in[1][2];

    cout << "R'" << endl; read_in();
    cout << "L" << endl; read_in();
    cout << "D'" << endl; read_in();

    cout << "A" << endl;
    rep(i, 0, 3) {
        cout << "   ";
        rep(j, 0, 3) cout << cube[4][i][j];
        cout << "   " << endl;
    }

    rep(i, 0, 3) {
        rep(j, 0, 3) cout << cube[3][i][j];
        rep(j, 0, 3) cout << cube[0][i][j];
        rep(j, 0, 3) cout << cube[1][i][j];
        cout << endl;
    }

    rep(i, 0, 3) {
        cout << "   ";
        rep(j, 0, 3) cout << cube[5][i][j];
        cout << "   " << endl;
    }
    rep(i, 0, 3) {
        cout << "   ";
        rep(j, 0, 3) cout << cube[2][i][j];
        cout << "   " << endl;
    }

}
