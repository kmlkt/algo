#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<int> p;

char solve() {
    int n;
    cin >> n;
    p.resize(n);
    if (n % 2 == 0) {
        for (int i = 1; i <= n / 2; ++i) {
            p[n - 2 * i] = i;
        }
        for (int i = 1; i <= n / 2; ++i) {
            p[n - 2 * i + 1] = i + (n / 2);
        }
    } else {
        p[n - 1] = n;
        for (int i = 1; i < n; ++i) {
            p[n - i - 1] = i;
        }
    }
    for (int pi : p) {
        cout << pi << ' ';
    }
    return ' ';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
