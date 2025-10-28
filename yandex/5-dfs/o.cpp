#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;
template <class T>
using table = vector<vector<T>>;

table<int> gr;
table<int> gb;
vector<int> used;
table<bool> comp_r;
table<bool> comp_b;

struct dfs_ans {
    int v;
    int dist;
};

void dfs(int v, table<int> &g, table<bool> &comp, int c) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    comp[v][v] = true;
    for (int u : g[v]) {
        dfs(u, g, comp, c);
        for (int w = 0; w < comp[u].size(); ++w) {
            comp[v][w] = comp[v][w] || comp[u][w];
        }
    }
}

int main() {
    int n;
    cin >> n;
    gr.resize(n);
    gb.resize(n);
    comp_b.resize(n, vector<bool>(n));
    comp_r.resize(n, vector<bool>(n));
    used.resize(n);
    string s;
    for (int i = 0; i < n - 1; ++i) {
        cin >> s;
        for (int j = 0; j < (n - i) - 1; ++j) {
            if (s[j] == 'R') {
                gr[i].push_back(i + j + 1);
            } else {
                gb[i].push_back(i + j + 1);
            }
        }
    }
    int c = 0;
    for (int u = 0; u < n; ++u) {
        if (used[u]) {
            continue;
        }
        dfs(u, gr, comp_r, c);
        ++c;
    }
    c = 0;
    fill(used.begin(), used.end(), 0);
    for (int u = 0; u < n; ++u) {
        if (used[u]) {
            continue;
        }
        dfs(u, gb, comp_b, c);
        ++c;
    }
    c = 0;
    fill(used.begin(), used.end(), 0);
    bool ans = false;
    for (int u = 0; u < n; ++u) {
        for (int v = u + 1; v < n; ++v) {
            if (comp_b[u][v] && comp_r[u][v]) {
                ans = true;
                break;
            }
        }
        if (ans) {
            break;
        }
    }
    cout << (ans ? "YES" : "NO");
}
