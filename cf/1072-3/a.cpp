#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int solve() {
    int n;
    cin >> n;
    if (n <= 3) {
        return n;
    }
    return n % 2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
