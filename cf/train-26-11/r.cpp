#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> rfree(n, 1);
    vector<bool> cfree(m, 1);
    int free_rows = n;
    int free_cols = m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int aij;
            cin >> aij;
            if(aij) {
                free_rows -= rfree[i];
                free_cols -= cfree[j];
                rfree[i] = cfree[j] = 0;
            }
        }
    }
    cout << ((min(free_rows, free_cols) % 2) ? "Ashish" : "Vivek") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
