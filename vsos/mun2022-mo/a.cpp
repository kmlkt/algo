#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    a *= 24 * 60 * 60;
    b *= 24 * 60;
    c *= 24;
    cout << min({a / x, b / y, c / z});
}
