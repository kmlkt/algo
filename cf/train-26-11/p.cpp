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
    int a, b;
    cin >> a >> b;
    int ans = 100000;
    for(int ob = 0; ob < 100; ++ob) {
        int b1 = b + ob;
        if(b1 <= 1) {
            continue;
        }
        int a1 = a;
        int oa = 0;
        while(a1 > 0) {
            a1 /= b1;
            ++oa;
        }
        if(oa + ob > ans) {
            break;
        }
        ans = oa + ob;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
