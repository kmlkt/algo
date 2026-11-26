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
    ll n, r;
    cin >> n >> r;
    if(n <= r) {
        cout << (n - 1)*n / 2 + 1;
    } else {
        cout << (r + 1) * r / 2;
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
