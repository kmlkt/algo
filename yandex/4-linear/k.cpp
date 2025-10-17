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
    vector<ll> a(n);
    for (ll &ai : a) {
        cin >> ai;
    }
    int mini = INT32_MAX;
    int mini_cnt = 0;
    for (int r = 0; r < k; ++r) {
        if (a[r] < mini) {
            mini = a[r];
            mini_cnt = 1;
        } else if (a[r] == mini) {
            ++mini_cnt;
        }
    }
    cout << mini << '\n';
    for (int r = k; r < n; ++r) {
        if (a[r - k] == mini) {
            --mini_cnt;
        }
    }
}
