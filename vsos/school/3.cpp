#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ll s;
    cin >> s;
    ll ans = s / 4;
    if (s % 4 == 0) {
        --ans;
    }
    if (s % 4 == 3) {
        ++ans;
    }
    if (s % 3 == 0) {
        --ans;
    }
    cout << ans;
}
