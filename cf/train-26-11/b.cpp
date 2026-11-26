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
    int n;
    cin >> n;
    int ans = 0;
    while(n % 6 == 0) {
        n /= 6;
        ++ans;
    }
    while(n % 3 == 0) {
        n /= 3;
        ans += 2;
    }
    cout << ((n == 1) ? ans : -1) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
