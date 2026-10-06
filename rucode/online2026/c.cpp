#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const int N = 26;

struct Course {
    array<int, N> lower;
    array<int, N> upper;

    void clear() {
        lower.fill(0);
        upper.fill(0);
    }

    void add_string(string s) {
        for (char c : s) {
            if ('a' <= c && c <= 'z') {
                ++lower[c - 'a'];
            } else {
                ++upper[c - 'A'];
            }
        }
    }

    void add_course(Course &c) {
        for (int i = 0; i < N; ++i) {
            lower[i] += c.lower[i];
            upper[i] += c.upper[i];
        }
    }

    bool contains(Course &c) {
        for (int i = 0; i < N; ++i) {
            if (lower[i] < c.lower[i] || upper[i] < c.upper[i]) {
                return false;
            }
        }
        return true;
    }

    bool contains_nocase(Course &c) {
        for (int i = 0; i < N; ++i) {
            if (lower[i] + upper[i] < c.lower[i] + c.upper[i]) {
                return false;
            }
        }
        return true;
    }

    int case_diff(Course &c) {
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (lower[i] < c.lower[i]) {
                ans += c.lower[i] - lower[i];
            }
            if (upper[i] < c.upper[i]) {
                ans += c.upper[i] - upper[i];
            }
        }
        return ans;
    }
};

const int M = 5;
Course current, sum;
array<Course, M> products;
array<int, M + 1> can_take;
array<int, M + 1> can_take_nocase;
array<int, M + 1> min_case_change;

void solve1() {
    current.clear();
    can_take.fill(0);
    can_take_nocase.fill(0);
    min_case_change.fill(INT32_MAX);
    string s;
    cin >> s;
    current.add_string(s);
    for (int mask = 0; mask < (1 << M); ++mask) {
        sum.clear();
        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            if (mask & (1 << i)) {
                sum.add_course(products[i]);
                ++cnt;
            }
        }
        if (current.contains(sum)) {
            ++can_take[cnt];
        }
        if (current.contains_nocase(sum)) {
            ++can_take_nocase[cnt];
            min_case_change[cnt] = min(min_case_change[cnt], current.case_diff(sum));
        }
    }
    int k = 0;
    int variants = 0;
    int k1 = 0;
    int case_change = 0;
    for (int i = 0; i <= M; ++i) {
        if (can_take[i]) {
            k = i;
            variants = can_take[i];
        }
        if (can_take_nocase[i]) {
            k1 = i;
            case_change = min_case_change[i];
        }
    }
    cout << k << ' ' << variants << ' ' << k1 << ' ' << case_change << '\n';
}

int main() {
    products[0].add_string("MWSOctapi");
    products[1].add_string("MWSAI");
    products[2].add_string("MWSTables");
    products[3].add_string("MWSData");
    products[4].add_string("MWSCloudPlatform");
    int t;
    cin >> t;
    while (t--) {
        solve1();
    }
}
