#include <algorithm>
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
    ll n, k;
    cin >> n >> k;
    cout << k + (k - 1) / (n - 1) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
