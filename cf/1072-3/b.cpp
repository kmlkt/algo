#include <iostream>

using namespace std;
using ll = long long;

int solve() {
    int s, k, m;
    cin >> s >> k >> m;
    if (s <= k) {
        int t = k;
        int phase = m % t;
        int rest = max(0, s - phase);
        return rest;
    }
    int t = 2 * k;
    int phase = m % t;
    if (phase < k) {
        int rest = max(0, s - phase);
        return rest;
    }
    int rest = max(0, k - (phase - k));
    return rest;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
