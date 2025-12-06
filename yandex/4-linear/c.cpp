#include <algorithm>
#include <cstdint>
#include <deque>
#include <iostream>
#include <numeric>
#include <stack>
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
    stack<ll> less;
    vector<ll> lessL(n);
    vector<ll> lessR(n);
    for (int i = 0; i < n; ++i) {
        ll ai = a[i];
        while (!less.empty() && a[less.top()] >= ai) {
            less.pop();
        }
        lessL[i] = less.empty() ? -1 : less.top();
        less.push(i);
    }
    while (!less.empty()) {
        less.pop();
    }
    for (int i = n - 1; i >= 0; --i) {
        ll ai = a[i];
        while (!less.empty() && a[less.top()] >= ai) {
            less.pop();
        }
        lessR[i] = less.empty() ? n : less.top();
        less.push(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, (lessR[i] - lessL[i] - 1) * a[i]);
    }
    cout << ans;
}
