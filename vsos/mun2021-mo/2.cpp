#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    string n;
    cin >> n;
    reverse(n.begin(), n.end());
    ll ans = 0;
    ll one = 1;
    for (char c : n) {
        if (c == '5') {
            ans += one;
        }
        one <<= 1;
    }
    ans += one;
    --ans;
    cout << ans;
}
