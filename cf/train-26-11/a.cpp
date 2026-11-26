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
    int x, y, n;
    cin >> x >> y >> n;
    int k = n - n % x - x * (n % x < y) + y;
    cout << k << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
