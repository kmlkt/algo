#include <algorithm>
#include <array>
#include <cmath>
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
    int n;
    cin >> n;
    int p2 = 1;
    while((p2 << 1) <= n) {
        p2 <<= 1;
    }
    cout << p2 - 1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
