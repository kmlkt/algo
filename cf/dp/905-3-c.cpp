#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    map<int, int> del;
    for (int ai : a) {
        for (int d = 2; d <= 5; ++d) {
            if (ai % d == 0) {
                ++del[d];
            }
        }
    }
    if (del[k]) {
        return 0;
    }
    if (a.size() == 1) {
        int diff = (k - a[0] % k);
        return diff;
    }
    if (k == 2) {
        return 1;
    }
    if (k == 3) {
        int mindiff = k;
        for (int ai : a) {
            mindiff = min(mindiff, k - ai % k);
        }
        return mindiff;
    }
    if (k == 4) {
        if (del[2] >= 2) {
            return 0;
        }
        if (del[2]) {
            return 1;
        }
        for (int ai : a) {
            if (ai % k == 3) {
                return 1;
            }
        }
        return 2;
    }
    if (k == 5) {
        int mindiff = k;
        for (int ai : a) {
            mindiff = min(mindiff, k - ai % k);
        }
        return mindiff;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
