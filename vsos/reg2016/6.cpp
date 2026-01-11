#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct tron {
    ll x;
    bool v;
    tron *comrade;
    tron *next[2];
    ll death_time;

    void calc_comrade() {
        if (v == 0 || next[0] == 0) {
            return;
        }
        if (next[1] == 0 || next[0]->x < next[1]->x) {
            comrade = next[0];
        } else {
            comrade = next[1]->comrade->next[0];
        }
        comrade->comrade = this;
    }

    void calc_death() {
        if (comrade == 0) {
            death_time = INT64_MAX;
            return;
        }
        death_time = (abs(comrade->x - x) + 1) / 2;
    }

    bool operator<(tron other) const {
        return death_time < other.death_time;
    }
};

int main() {
    int n;
    cin >> n;
    vector<tron> a(n);
    for (tron &ai : a) {
        int v;
        cin >> ai.x >> v;
        ai.v = (v == 1);
    }
    tron *last[2] = {0, 0};
    for (int i = n - 1; i >= 0; --i) {
        tron &ai = a[i];
        ai.next[0] = last[0];
        ai.next[1] = last[1];
        last[ai.v] = &ai;
    }
    for (int i = n - 1; i >= 0; --i) {
        tron &ai = a[i];
        ai.calc_comrade();
    }
    for (tron &ai : a) {
        ai.calc_death();
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    for (int j = 0; j < m; ++j) {
        ll t;
        cin >> t;
        tron sorter;
        sorter.death_time = t;
        auto ub = upper_bound(a.begin(), a.end(), sorter);
        ll ans = a.end() - ub;
        cout << ans << '\n';
    }
}
