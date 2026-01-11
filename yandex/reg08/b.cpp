#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int n, q;
vector<vector<bool>> a;
vector<vector<int>> ps;
vector<vector<int>> down;

int sz(int i, int j) {
    return (n - i) * (n - j);
}

int get(int i, int j) {
    if (i >= n || j >= n) {
        return 0;
    }
    return ps[i][j];
}

int main() {
    cin >> n >> q;
    a.resize(n, vector<bool>(n));
    ps.resize(n, vector<int>(n));
    down.resize(n, vector<int>(n));
    vector<pair<int, int>> pod(q);
    for (auto &p : pod) {
        cin >> p.first >> p.second;
        --p.first;
        --p.second;
        a[p.first][p.second] = 1;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            ps[i][j] = get(i + 1, j) + get(i, j + 1) - get(i + 1, j + 1) + a[i][j];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int lastD = n;
        for (int j = n - 1; j >= 0; --j) {
            down[i][j] = lastD - j;
            if (a[i][j]) {
                lastD = j;
            }
        }
    }
    for (auto [i, j] : pod) {
        int ans = 0;
        int d = n;
        for (int x = i; x < n; ++x) {
            d = min(d, down[x][j]);
            ans += d;
        }
        cout << ans << '\n';
    }
}
