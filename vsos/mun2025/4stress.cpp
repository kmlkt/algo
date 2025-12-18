#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &ai : a) {
        cin >> ai;
    }
    for (int i = 0; i < n; ++i) {
        ll S = a[i];
        for (int j = i + 1; j < n; ++j) {
            ll x = a[j];
            if (x <= S) {
                S += x;
            } else {
                break;
            }
        }
        cout << S << '\n';
    }
}
