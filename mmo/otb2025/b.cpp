#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int n, k;
map<int, vector<int>> cache;
map<int, int> cache_outcnt;
map<pair<int, int>, int> indices;
vector<int> prev_pos_of;
vector<int> good_cnt;

int msb(int x) {
    int ans = 0;
    while (x != 0) {
        x >>= 1;
        ++ans;
    }
    return 1 << (ans - 1);
}

vector<int> &calc(int len, int &out_cnt) {
    if (cache.find(len) == cache.end()) {
        cache[len] = vector<int>(n);
        auto &ans = cache[len];
        int l1 = msb(len);
        if (l1 == len) {
            l1 = len / 2;
        }
        int l2 = len - l1;
        int _ = 0;
        auto &p1 = calc(l1, _);
        auto &p2 = calc(l2, _);
        for (int i = 0; i < n - l1; ++i) {
            ++indices[{p1[i], p2[i + l1]}];
        }
        int ps = 1;
        for (auto &cnt : indices) {
            cnt.second = ps;
            ++ps;
        }

        for (int i = 0; i < n - l1; ++i) {
            ans[i] = indices[{p1[i], p2[i + l1]}];
        }
        fill(prev_pos_of.begin(), prev_pos_of.end(), -1);
        fill(good_cnt.begin(), good_cnt.end(), 1);
        for (int i = 0; i < n - l1; ++i) {
            if (prev_pos_of[ans[i]] != -1) {
                int dist = i - prev_pos_of[ans[i]];
                if (dist >= len) {
                    ++good_cnt[ans[i]];
                }
            }
            prev_pos_of[ans[i]] = i;
        }
        out_cnt = *max_element(good_cnt.begin(), good_cnt.end());

        indices.clear();
        cache_outcnt[len] = out_cnt;
    }
    out_cnt = cache_outcnt[len];
    return cache[len];
}

int main() {
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 1) {
        cout << n;
        return 0;
    }
    good_cnt.resize(n + 2);
    prev_pos_of.resize(n + 2);
    cache[1] = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cache[1][i] = s[i];
    }
    int _ = 0;
    calc(2, _);
    int l = 1; // out_cnt(l) >= k
    int r = n; // out_cnt(r) < k
    while (l < r - 1) {
        int m = (l + r) / 2;
        int cnt = 0;
        calc(m, cnt);
        if (cnt < k) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l;
}
