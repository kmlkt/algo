#include <algorithm>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n;
    int m, k;
    cin >> n >> m >> k;
    vector<set<ll>> sets(m + 1);
    map<ll, set<int>> setsof;
    string cmd;
    int s;
    ll e;
    while (k--) {
        cin >> cmd;
        switch (cmd[0] + cmd[cmd.size() - 1]) {
        case 'A' + 'D':
            cin >> e >> s;
            sets[s].insert(e);
            setsof[e].insert(s);
            break;
        case 'D' + 'E':
            cin >> e >> s;
            sets[s].erase(e);
            setsof[e].erase(s);
            break;
        case 'C' + 'R':
            cin >> s;
            for (ll l : sets[s]) {
                setsof[l].erase(s);
            }
            sets[s].clear();
            break;
        case 'L' + 'T':
            cin >> s;
            if (sets[s].size() == 0) {
                cout << "-1";
            }
            for (ll l : sets[s]) {
                cout << l << " ";
            }
            cout << "\n";
            break;
        case 'L' + 'F':
            cin >> e;
            int cnt = 0;
            int i = 0;
            if (setsof[e].size() == 0) {
                cout << "-1";
            }
            for (auto st : setsof[e]) {
                cout << st << " ";
            }
            cout << "\n";
            break;
        }
    }
}
