#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int h, w;
    cin >> h >> w;
    // h = 1;
    ll sum = 0;
    vector<vector<int>> a(h, vector<int>(w));
    for (auto &r : a) {
        for (auto &c : r) {
            cin >> c;
            sum += c;
        }
    }
    ll s;
    cin >> s;
    ll needRem = sum - s;
    int lim = 1 << w;
    int ans = -1;
    for (int mask = 0; mask < lim; ++mask) {
        ll rem = 0;
        for (int i = 0; i < w; ++i) {
            if (mask & (1 << i)) {
                rem += a[0][i];
            }
        }
        if (rem == needRem) {
            ans = mask;
            break;
        }
    }
    if (ans == -1) {
        cout << "NO";
    } else {
        cout << "YES\n";
        vector<int> anslist;
        for (int i = 0; i < w; ++i) {
            if (ans & (1 << i)) {
                anslist.push_back(i);
            }
        }
        cout << anslist.size() << '\n';
        for (int i : anslist) {
            cout << "2 " << (i + 1) << '\n';
        }
    }
}
