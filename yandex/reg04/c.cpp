#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int a, b, c, d;
vector<vector<bool>> l;
vector<vector<int>> comp;

bool dfs(int i, int j, int timer, int cmp) {
    if (i < a || c <= i || j < b || d <= j) {
        return false;
    }
    if (comp[i][j] >= timer || !l[i][j]) {
        return false;
    }
    comp[i][j] = cmp;
    dfs(i - 1, j, timer, cmp);
    dfs(i + 1, j, timer, cmp);
    dfs(i, j - 1, timer, cmp);
    dfs(i, j + 1, timer, cmp);
    return true;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    l.resize(n, vector<bool>(m));
    comp.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            l[i][j] = (i & j) == 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << (l[i][j] ? '0' : ' ');
        }
        cout << '\n';
    }
    return 0;
    int timer = 0;
    while (q--) {
        cin >> a >> b >> c >> d;
    }
    for (a = 0; a < n; ++a) {
        for (b = 0; b < m; ++b) {
            cout << a << ' ' << b << '\n';
            for (c = a + 1; c <= n; ++c) {
                for (d = b + 1; d <= m; ++d) {
                    //++c;
                    //++d;
                    int cmp = timer;
                    for (int i = a; i < c; ++i) {
                        for (int j = b; j < d; ++j) {
                            cmp += dfs(i, j, timer, cmp);
                        }
                    }
                    cout << (cmp - timer) << ' ';
                    timer = cmp;
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
}
