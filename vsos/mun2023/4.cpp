#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int ans;

void calc(ll x) {
    ans = 0;
    for (ll y = 1; y < 2 * x; ++y) {
        ll zz = x * x + y * y;
        ll z = sqrt(zz);
        if (z * z == zz) {
            ++ans;
        }
    }
}

int main() {
    int n = 100000;
    vector<bool> simple_resh(n, 1);
    for (int i = 2; i < n; ++i) {
        if (!simple_resh[i]) {
            continue;
        }
        for (int j = i * 2; j < n; j += i) {
            simple_resh[j] = false;
        }
    }
    vector<int> simple;
    for (int i = 2; i < n; ++i) {
        if (simple_resh[i]) {
            simple.push_back(i);
        }
    }

    for (int x = 0; x < 1000; ++x) {
        calc(x);
        if (ans != 0) {
            cout << x << ": " << ans << "\n";
        }
    }
}
