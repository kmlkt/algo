#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ii = vector<int>::iterator;
using ll = long long;

int n, m;
vector<int> a;

bool check(vector<int> &ai, vector<int> &bj, int k) {
    return ai[k] <= bj[k];
}

int main() {
    cin >> n >> m;
    a.resize(n);
    for (int &ai : a) {
        cin >> ai;
    }
    vector<ii> next(n, a.end());
    map<int, ii> first;

    for (ii it = a.end() - 1; it >= a.begin(); --it) {
        int ai = *it;
        auto nxt = first.find(ai);
        if (nxt == first.end()) {
            first[ai] = it;
            continue;
        }
        next[it - a.begin()] = nxt->second;
        nxt->second = it;
    }
    /*for (auto &[k, v] : first) {
        cout << k << ": ";
        for (ii it = v; it < a.end(); it = next[it - a.begin()]) {
            cout << (it - a.begin()) << " ";
        }
        cout << "\n";
        }*/
    vector<ll> beforeEq(n);
    vector<ll> afterDiff(n);
    for (auto &[k, v] : first) {
        int cnt = 0;
        for (ii it = v; it < a.end(); it = next[it - a.begin()]) {
            beforeEq[it - a.begin()] = cnt;
            ++cnt;
        }
        for (ii it = v; it < a.end(); it = next[it - a.begin()]) {
            int afterEq = cnt - beforeEq[it - a.begin()] - 1;
            int after = a.end() - it - 1;
            afterDiff[it - a.begin()] = after - afterEq;
        }
    }

    map<int, ll> ans;
    for (int i = 0; i < n; ++i) {
        ans[a[i]] = max(ans[a[i]], (beforeEq[i] + 1) * afterDiff[i]);
    }

    while (m--) {
        int x;
        cin >> x;
        cout << ans[x] << ' ';
    }
}
