#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = min({a + b - c, a + c - b, b + c - a});
    cout << x;
}
