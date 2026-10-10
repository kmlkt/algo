#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 0; i < k - 1; ++i) {
        ans += 2;
    }
    int c = 1;
    for(int i = k - 1; i < n; ++i) {
        c *= 2;
    }
    ans += c;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
