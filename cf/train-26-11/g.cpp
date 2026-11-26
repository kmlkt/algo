#include <algorithm>
#include <array>
#include <cmath>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;


void solve() {
    int n, k;
    cin >> n >> k;
    int sz = 1;
    for(int i = 1; i * i <= n && i <= k; ++i) {
        if(n % i == 0) {
            sz = max(sz, i);
            if(n / i <= k) {
                sz = n / i;
                break;
            }
        }
    }
    cout << n / sz << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
