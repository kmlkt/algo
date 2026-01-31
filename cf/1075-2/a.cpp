#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// vector<int> a;

int solve() {
    int n, h, l;
    cin >> n >> h >> l;
    // a.resize(n);
    int mh = 0;
    int ml = 0;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        if (ai <= h) {
            ++mh;
        }
        if (ai <= l) {
            ++ml;
        }
    }
    int ans = min(max(ml, mh) / 2, min(ml, mh));
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
