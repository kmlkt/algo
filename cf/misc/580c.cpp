#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<bool> cat(n);
    for(int i = 0; i < n; ++i) {
        int cati;
        cin >> cati;
        cat[i] = cati;
    }
    for(int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;
    auto dfs = [&](auto &self, int v, int p, int c) -> void {
        if(cat[v]) {
            ++c;
        } else {
            c = 0;
        }
        if(c > m) {
            return;
        }
        if(g[v].size() == 1 && p != -1) {
            ++ans;
        }
        for(int to : g[v]) {
            if(to != p) {
                self(self, to, v, c);
            }
        }
    };
    dfs(dfs, 0, -1, 0);
    cout << ans << '\n';
}
