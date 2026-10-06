#include <array>
#include <iostream>

using namespace std;
using ll = long long;

void solve1() {
    ll k;
    cin >> k;
    if (k % 2 == 1) {
        cout << '3';
        k -= 1;
    } else {
        cout << '8';
        k -= 2;
    }
    while (k > 0) {
        cout << '9';
        k -= 2;
    }
    cout << '\n';
}

void solve2() {
    string x;
    cin >> x;
    ll k = 0;
    if (x[0] <= '3') {
        k = x.size() * 2 - 1;
    } else if (x[0] <= '8') {
        k = x.size() * 2;
    } else {
        k = x.size() * 2 + 1;
    }
    cout << k << '\n';
}

const int N = 1e5;

int main() {
    int q;
    cin >> q;
    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            solve1();
        } else {
            solve2();
        }
    }
}
