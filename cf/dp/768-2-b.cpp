#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

vector<int> a;

int solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (int &ai : a) {
        cin >> ai;
    }
    int l = n - 1;
    while (l > 0 && a[l - 1] == a[l]) {
        --l;
    }
    int ans = 0;
    while (l > 0) {
        ++ans;
        int d = n - l;
        for (int i = 0; i < d; ++i) {
            int j = l - i - 1;
            if (j < 0) {
                break;
            }
            a[j] = a[l];
        }
        while (l > 0 && a[l - 1] == a[l]) {
            --l;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
