#include <algorithm>
#include <cstdint>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    ll ans = 0;
    for (int l = 0; l < n; ++l) {
        int r = l;
        int cur = 0;
        for (; r < n; ++r) {
            cur |= a[r];
            if (cur >= k) {
                break;
            }
        }
        ans += n - r;
        if (r == n) {
            break;
        }
    }
    cout << ans;
}
