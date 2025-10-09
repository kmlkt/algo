#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll n;

bool check(ll x) {
    cout << "? " << x + 1 << endl;
    int t;
    cin >> t;
    return t;
}

int main() {
    cin >> n;
    ll l = 0;     // check(l) = true
    ll r = n - 1; // check(r) = false
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << "! " << l + 1;
}
