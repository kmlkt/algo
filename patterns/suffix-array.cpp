#include <algorithm>
#include <any>
#include <cmath>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct suffix {
    int index;
    pair<int, int> rank;
    bool operator<(suffix another) {
        return rank < another.rank;
    }
};

vector<suffix> buildSuffixArray(string input) {
    int sz = input.size();
    vector<suffix> sa(sz);
    vector<suffix *> whereis(sz);
    for (int i = 0; i < sz; ++i) {
        sa[i].index = i;
        sa[i].rank.first = input[i];
        sa[i].rank.second = (i + 1 == sz) ? -1 : input[i + 1];
    }
    sort(sa.begin(), sa.end());
    for (int k = 4; k < sz * 2; k *= 2) {
        int rank = -1;
        auto prev_rank = make_pair(-1, -1);
        for (suffix &s : sa) {
            if (s.rank != prev_rank) {
                ++rank;
                prev_rank = s.rank;
            }
            s.rank.first = rank;
            whereis[s.index] = &s;
        }
        for (suffix &s : sa) {
            s.rank.second = (s.index + k >= sz) ? -1 : whereis[s.index + k]->rank.first;
        }
        sort(sa.begin(), sa.end());
    }
    return sa;
}

int main() {
    string input = "verylongname";
    auto sa = buildSuffixArray(input);
    for (suffix s : sa) {
        cout << s.index << ' ';
    }
    cout << endl;
    for (suffix s : sa) {
        cout << input.substr(s.index) << endl;
    }
}
