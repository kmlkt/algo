#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    int q;
    cin >> q;
    vector<pair<int, int>> s(q);
    for (auto &si : s) {
        cin >> si.first >> si.second;
    }
    reverse(s.begin(), s.end());
    for (auto &si : s) {
        if (si.first <= k && k <= si.second) {
            k = si.second - (k - si.first);
        }
    }
    cout << a[k - 1];
}
