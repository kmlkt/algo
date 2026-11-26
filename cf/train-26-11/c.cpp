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
    int a, b;
    cin >> a >> b;
    cout << min({(a + b) / 3, a, b}) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
