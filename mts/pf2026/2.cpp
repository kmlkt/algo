#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <array>

using namespace std;
using ll = long long;

int solve() {
    string s;
    cin >> s;
    array<bool, 10> red;
    red.fill(0);
    int active = -1;
    vector<pair<int, int>> seg;
    for(char c : s) {
        int x = c - '0';
        if(active == -1) {
            active = x;
            red[x] = 1;
            continue;
        }
        if(red[x]) {
            return -1;
        }
        int perekr = -1;
        if((active == 1 || active == 2 || active == 3) && x == active + 6) {
            perekr = active + 3;
        } else if((active == 7 || active == 8 || active == 9) && x == active - 6) {
            perekr = active - 3;
        } else if((active == 1 || active == 4 || active == 7) && x == active + 2) {
            perekr = active + 1;
        } else if((active == 3 || active == 6 || active == 9) && x == active - 2) {
            perekr = active - 1;
        } else if((active == 1 && x == 9) || (active == 9 && x == 1) ||
            (active == 3 && x == 7) || (active == 7 && x == 3)) {
            perekr = 5;
        }

        if(perekr == -1) {
            seg.push_back({active, x});
        } else {
            seg.push_back({active, perekr});
            seg.push_back({perekr, x});
            red[perekr] = 1;
        }
        red[x] = 1;
        active = x;
    }
    for(auto &p : seg) {
        if(p.first > p.second) {
            swap(p.first, p.second);
        }
    }
    int ans = 0;
    for(auto &p : seg) {
        int cnt = count(seg.begin(), seg.end(), p) - 1;
        int len = (p.second == p.first + 4 || p.second == p.first + 2) ? 2 : 1;
        ans += cnt * len;
    }
    return ans / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
