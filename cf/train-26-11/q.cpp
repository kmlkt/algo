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
    vector<vector<int>> a(n, vector<int>(m));
    int negcnt = 0;
    int minmod = 1000000;
    int sum = 0;
    for(auto &ai : a) {
        for(int &aij : ai) {
            cin >> aij;
            minmod = min(minmod, abs(aij));
            sum += abs(aij);
            if(aij < 0) {
                ++negcnt;
            }
        }
    }
    if(negcnt % 2) {
        sum -= 2 * minmod;
    }
    cout << sum << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
