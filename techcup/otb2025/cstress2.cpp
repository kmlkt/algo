#include <cstdlib>
#include <iostream>
#include <utility>

using namespace std;
using ll = long long;

string s;
bool allones = true;
bool allzeros = true;

bool is3(int l, int r) {
    ll x = 0;
    for (int i = l; i < r; ++i) {
        x += (s[i] - '0') << (i - l);
    }
    return x % 3 == 0;
}

void solve() {
    int l, r;
    cin >> l >> r;
    --l;
    if (allones) {
        int d = r - l - 1;
        if (d % 2 == 0) {
            cout << 0;
        } else {
            cout << d;
        }
        cout << "\n";
        return;
    }
    if (allzeros) {
        int d = r - l - 1;
        cout << d;
        cout << "\n";
        return;
    }
    ll ans = 0;
    for (int i = l; i < r - 1; ++i) {
        swap(s[i], s[i + 1]);
        if (is3(l, r)) {
            ++ans;
        }
        swap(s[i], s[i + 1]);
    }
    cout << ans << "\n";
}

int main() {
    cin >> s;
    for (char c : s) {
        if (c != '1') {
            allones = false;
        }
        if (c != '0') {
            allzeros = false;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
