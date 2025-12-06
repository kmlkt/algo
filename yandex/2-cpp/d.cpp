#include <algorithm>
#include <array>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int q;
    cin >> q;
    map<string, ll> stock;
    map<string, int> order;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            string name;
            cin >> name;
            int n;
            cin >> n;
            int ok = true;
            for (int i = 0; i < n; ++i) {
                string s;
                int k;
                cin >> k >> s;
                order[s] += k;
                if (stock[s] < order[s]) {
                    ok = false;
                }
            }
            if (!ok) {
                cout << ":(\n";
                order.clear();
                continue;
            }
            for (auto &[s, k] : order) {
                stock[s] -= k;
            }
            cout << "Milkshake " << name << " is ready\n";
            order.clear();
        } else {
            string s;
            int k;
            cin >> k >> s;
            stock[s] += k;
            cout << s << ": " << stock[s] << "\n";
        }
    }
}
