#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    if(n < 4) {
        cout << "-1\n";
        return;
    }
    int i3 = 3;
    for(;i3 <= n; i3 += 4) {
        cout << i3 << ' ';
    }
    int i1 = 1;
    for(;i1 <= n; i1 += 4) {
    }
    i1 -= 4;
    for(;i1 > 0; i1 -= 4) {
        cout << i1 << ' ';
    }
    int i0 = 4;
    for(;i0 <= n; i0 += 4) {
        cout << i0 << ' ';
    }
    int i2 = 2;
    for(;i2 <= n; i2 += 4) {
    }
    i2 -= 4;
    for(;i2 > 0; i2 -= 4) {
        cout << i2 << ' ';
    }

    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
