#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    int n, d1, s1, p1, d2, s2, p2;
    cin >> n >> d1 >> s1 >> p1 >> d2 >> s2 >> p2;
    int ans;
    if (s1 < n) {
        ans = 2;
    } else if (s2 < n) {
        ans = 1;
    } else if (d1 < d2) {
        ans = 2;
    } else if (d2 < d1) {
        ans = 1;
    } else {
        ans = -1;
    }
    int p = ans == -1 ? min(p1, p2) : (ans == 1 ? p1 : p2);
    cout << p * n << '\n';
    if (ans == 1) {
        cout << 1 << '\n';
    }
    if (ans == 2) {
        cout << 2 << '\n';
    }
    if (ans == -1) {
        if (p == p1) {
            cout << 1 << '\n';
        }
        if (p == p2) {
            cout << 2 << '\n';
        }
    }
}
