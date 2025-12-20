#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

vector<int> a;

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int &ai : a) {
        cin >> ai;
    }
    vector<int> u(n, 1);
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] < a[i]) {
            u[i] = u[i - 1] + 1;
        }
    }
    vector<int> d(n, 1);
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > a[i + 1]) {
            d[i] = d[i + 1] + 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += u[i] * d[i];
    }
    cout << ans;
}
