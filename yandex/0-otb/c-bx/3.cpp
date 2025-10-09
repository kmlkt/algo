#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    if (n == 1) {
        if (m == 2) {
            cout << 1;
            return 0;
        }
        if (m == 3) {
            cout << 0;
            return 0;
        }
    }
    if (n == 2) {
        cout << 0;
        return 0;
    }
    if (n > 2)
        n -= 2;
    if (m > 2)
        m -= 2;
    cout << n * m;
}
