#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll &ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());
    ll m = n / 2;
    ll nxt = m + 1;
    ll k1 = k;
    while(k1 > 0 && nxt < n) {
        ll d = a[nxt] - a[m];
        if(d * (nxt - m) >= k1) {
            a[m] += k1 / (nxt - m);
            k1 = 0;
        } else {
            a[m] = a[nxt];
            k1 -= d * (nxt - m);
            ++nxt;
        }
    }
    a[m] += k1 / (nxt - m);
    cout << a[m];
}
