#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int mx, mn;
    if (n - (a + b + c) > 0) {
        mn = n - (a + b + c);
    } else {
        mn = 0;
    }

    mx = n - max({a, b, c});

    cout << mn << "\n"
         << mx;
}
