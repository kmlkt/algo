#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << abs(a * b - c * d);
}
