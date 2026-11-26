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

const int INF = 1e9;

void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    int l_nedel = -1;
    int r_nedel = -1;
    for(int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        sum += ai;
        if(ai % x) {
            if(l_nedel == -1) {
                l_nedel = i;
            }
            r_nedel = i;
        }
    }
    if(sum % x) {
        cout << n;
    } else if(l_nedel != -1) {
        cout << max(n - (l_nedel + 1), r_nedel);
    } else {
        cout << -1;
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
