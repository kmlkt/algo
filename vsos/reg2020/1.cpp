#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll k, a, x, b, y;
    cin >> k >> a >> x >> b >> y;
    ll ab = (k - a) * x + (k - a - b) * y;
    ll ba = (k - a - b) * x + (k - b) * y;
    cout << max(ab, ba);
}
