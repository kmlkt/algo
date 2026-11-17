#include <algorithm>
#include <array>
#include <bitset>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


int n;
vector<vector<int>> g;
vector<bool> used;
vector<int> sz;

void dfs_sz(int v) {
    for(int to : g[v]) {
        if(!used[to]) {
            used[to] = 1;
            dfs_sz(to);
            sz[v] += sz[to];
        }
    }
}

int ans = 0;
void dfs_ans(int v) {
    vector<int> tmp;
    for(int to : g[v]) {
        if(!used[to]) {
            tmp.push_back(sz[to]);
        }
    }
    if(tmp.size() >= 2) {
        sort(tmp.begin(), tmp.end());
        ans = max(ans, tmp[tmp.size() - 2]);
    }
    for(int to : g[v]) {
        if(!used[to]) {
            used[to] = 1;
            dfs_ans(to);
        }
    }
}

void solve() {
    cin >> n;
    ans = 0;
    g.resize(n);
    sz.resize(n);
    used.resize(n);
    fill(g.begin(), g.end(), vector<int>(0));
    fill(sz.begin(), sz.end(), 1);
    fill(used.begin(), used.end(), 0);

    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    used[0] = 1;
    dfs_sz(0);
    fill(used.begin(), used.end(), 0);
    used[0] = 1;
    dfs_ans(0);

    cout << n - ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
