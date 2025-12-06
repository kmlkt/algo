#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> used;

struct dfs_ans {
    int v;
    int dist;
};

dfs_ans dfs(int v) {
    if (used[v]) {
        return {v, 0};
    }
    used[v] = true;
    dfs_ans ans = {v, 0};
    for (int u = 0; u < g[v].size(); ++u) {
        auto ansu = dfs(u);
        ansu.dist += g[u][v];
        if (ansu.dist > ans.dist) {
            ans = ansu;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    g.resize(n, vector<int>(n));
    used.resize(n);
    for (auto &v : g) {
        for (auto &u : v) {
            cin >> u;
        }
    }
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            for (int t = 0; t < n; ++v) {
            }
        }
    }
}
