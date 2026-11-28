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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(string &ai : a) {
        cin >> ai;
    }
    if(a[n-1][m-1] == 'B') {
        cout << "NO\n";
        return;
    }
    auto to = [&](int i, int j) {
        vector<pair<int, int>> to;
        if(i > 0) {
            to.push_back({i-1, j});
        }
        if(j > 0) {
            to.push_back({i, j-1});
        }
        if(i + 1 < n) {
            to.push_back({i+1, j});
        }
        if(j + 1 < m) {
            to.push_back({i, j+1});
        }
        return to;
    };
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(a[i][j] == 'B') {
                for(auto [i1, j1] : to(i, j)) {
                    if(a[i1][j1] == 'G') {
                        cout << "NO\n";
                        return;
                    } else if(a[i1][j1] == '.') {
                        a[i1][j1] = '#';
                    }
                }
            }
        }
    }
    auto dfs = [&](auto self, int i, int j) {
        if(a[i][j] != '.' && a[i][j] != 'G') {
            return;
        }
        a[i][j] = ':';
        for(auto [i1, j1] : to(i, j)) {
            self(self, i1, j1);
        }
    };
    dfs(dfs, n-1, m-1);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(a[i][j] == 'G'){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
