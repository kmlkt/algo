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
    ll n;
    cin >> n;
    ll ia = 0;
    ll ib = 0;
    ll last = 1;
    while (ia + ib < n) {
        ll ianext = ia + 1;
        ll ibnext = ib + 1;

        ll anext = ianext * ianext;
        ll bnext = ibnext * ibnext * ibnext;

        if (anext < bnext) {
            ia = ianext;
            last = anext;
        } else if (anext == bnext) {
            ia = ianext;
            ib = ibnext;
            last = anext;
            ++n;
        } else {
            ib = ibnext;
            last = bnext;
        }
    }
    cout << last << ' ';
}
