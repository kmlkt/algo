#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll top = a * n;
    ll bottom = a + b;
    if (top % bottom == 0) {
        cout << top / bottom;
    } else {
        cout << -1;
    }
}
