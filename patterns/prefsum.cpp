#include <array>
#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    vector<ll> ps(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        ps[i] = sum;
    }
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    int ans;
    if (l == 0) {
        ans = ps[r];
    } else {
        ans = ps[r] - ps[l - 1];
    }
    cout << ans;
}
