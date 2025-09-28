#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = INT32_MAX;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;

    for (int &ai : a) {
        cin >> ai;
        sum += ai;
    }
    if (sum % n) {
        cout << -1;
        return 0;
    }
    int mid = sum / n;
    int bad = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < mid) {
            ++bad;
        }
    }
    vector<int> needl(n);
    vector<int> needr(n);
    int ans = 0;
    while (bad) {
        ++ans;
        for (int i = 1; i < n; ++i) {
            needl[i] = 0;
            if (a[i] == 0) {
                continue;
            }
            if (a[i - 1] < mid) {
                needl[i] += mid - a[i - 1];
            }
            if (needl[i - 1]) {
                needl[i] += needl[i - 1];
                if (a[i - 1] > mid) {
                    --needl[i];
                }
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            needr[i] = 0;
            if (a[i] == 0) {
                continue;
            }
            if (a[i + 1] < mid) {
                needr[i] += mid - a[i + 1];
            }
            if (needr[i + 1]) {
                needr[i] += needr[i + 1];
                if (a[i + 1] > mid) {
                    --needr[i];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (needl[i] == 0 && needr[i] == 0) {
                continue;
            }
            if (needl[i] > needr[i]) {
                if (a[i] > a[i - 1]) {
                    ++a[i - 1];
                    --a[i];
                }
            } else {
                if (a[i] > a[i + 1]) {
                    ++a[i + 1];
                    --a[i];
                }
            }
        }
        bad = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < mid) {
                ++bad;
            }
        }
    }
    cout << ans;
}
