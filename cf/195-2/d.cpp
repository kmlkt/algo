#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> g;
vector<int> unknown_neig;
vector<int> color;
vector<int> comp;

void dfs_comp(int v, int c) {
    comp[v] = c;
    for(int to : g[v]) {
        if(comp[to] == -1) {
            dfs_comp(to, c);
        }
    }
}

void dfs_color(int v, int c) {
    color[v] = c;
    for(int to : g[v]) {
        --unknown_neig[to];
    }
    for(int to : g[v]) {
        if(unknown_neig[to] == 1) {

        }
    }

}

void solve() {
    g.clear();
    comp.clear();

    cin >> n >> m;
    g.resize(n);
    comp.resize(n, -1);

    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int c = 0;
    for(int v = 0; v < n; ++v) {
        if(comp[v] == -1) {
            dfs_comp(v, c);
            c++;
        }
    }
    vector<vector<int>> groups(c);
    for(int v = 0; v < n; ++v) {
        groups[comp[v]].push_back(v);
    }

    for(auto &group : groups) {
        if(group.size() == 1) {
            cout << "Brain Melt\n";
            return;
        }
    }
    if(groups.size() == 1) {
        auto &group = groups[0];
        int count_not_one = 0;
        for(int v : group) {
            if(g[v].size() > 1) {
                ++count_not_one;
            }
        }
        if(count_not_one <= 1) {
            cout << "2\n";
            return;
        }
    }
    cout << "Many\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
