#include <algorithm>
#include <cstdint>
#include <deque>
#include <iostream>
#include <numeric>
#include <set>
#include <stack>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    set<ll> ans;
    for (int i = 1; i <= n; ++i) {
        ans.insert(i * i);
        ans.insert(i * i * i);
    }
    int i = 0;
    for (ll ansi : ans) {
        i++;
        if (i == n) {
            cout << ansi;
            break;
        }
    }
}
