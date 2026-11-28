#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<pair<int, int>> e(m);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[i] = {u, v};
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool ans = 1;
    vector<int> col(n);
    auto dfs = [&](auto &self, int v) -> void {
        for(int to : g[v]) {
            if(col[to] == col[v]) {
                ans = 0;
                return;
            }
            if(!col[to]) {
                col[to] = 3 - col[v];
                self(self, to);
            }
        }
    };
    col[0] = 1;
    dfs(dfs, 0);
    if(ans) {
        cout << "YES" << '\n';
        for(int i = 0; i < m; ++i) {
            auto [u, v] = e[i];
            cout << (col[u] < col[v]);
        }
    } else {
        cout << "NO" << '\n';
    }
}
