#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

struct suffix {
    int index;
    pair<int, int> rank;
    bool operator<(suffix &other) const {
        return rank < other.rank;
    }
};
array<suffix, 7> a;
array<suffix *, 7> whereis;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        a[i].index = i;
        a[i].rank = {s[i], (i + 1 < n) ? s[i + 1] : -1};
    }
    sort(a.begin(), a.end());
    for (int k = 2; k < 2 * n; ++k) {
        pair<int, int> prev_rank = {-1, -1};
        int rank = 0;
        for (suffix &ai : a) {
            whereis[ai.index] = &ai;
            if (ai.rank != prev_rank) {
                ++rank;
                prev_rank = ai.rank;
            }
            ai.rank.first = rank;
        }
        for (suffix &ai : a) {
            int nextpos = ai.index + k;
            ai.rank.second = nextpos < n ? whereis[nextpos]->rank.first : -1;
        }
        sort(a.begin(), a.end());
    }
    for (auto pi : a) {
        cout << s.substr(pi.index) << '\n';
    }
}
