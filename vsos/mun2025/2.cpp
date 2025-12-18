#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int x;
    cin >> x;
    int ans = 0;
    for (int slag = 1; slag <= x; slag <<= 1) {
        if (x & slag) {
            ++ans;
        }
    }
    cout << ans;
}
