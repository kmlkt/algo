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

struct passenger {
    int stay;
    int sit;
    int start;
    int end;
    bool better_stay() {
        return stay >= sit;
    }
    int sit_profit() {
        return sit - stay;
    }
    bool operator<(passenger other) {
        return sit_profit() < other.sit_profit();
    }
};

const int HALFDIST = 1e6;
const int DIST = 2 * 1e6 + 5;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<passenger> a(n);
    vector<pair<bool, passenger *>> event(n * 2);
    for (int i = 0; i < n; ++i) {
        auto &pi = a[i];
        cin >> pi.sit >> pi.stay >> pi.start >> pi.end;

        pi.start += HALFDIST;
        pi.end += HALFDIST;
        event[i * 2] = {false, &pi};
        event[i * 2 + 1] = {true, &pi};
    }
    sort(event.begin(), event.end(), [](const auto &l, const auto &r) {
        int ltime = l.first ? l.second->end : l.second->start;
        int rtime = r.first ? r.second->end : r.second->start;
        if (ltime == rtime) {
            return l.first > r.first;
        }
        return ltime < rtime;
    });

    multiset<passenger *> cur;
    for (int i = 0; i < DIST; ++i) {
    }
}
