#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1;
        return 0;
    }
    for (int diff = -1; diff > -2 * n; diff -= 2) {
        for (int i = 0; i < n; ++i) {
            int j = (n * n + i + diff) % n;
            while (j < 0) {
                j += n;
            }
            cout << n - j << ' ';
        }
        cout << '\n';
    }
}
