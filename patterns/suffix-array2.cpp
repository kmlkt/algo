#include <algorithm>
#include <cmath>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct Suffix {
    int i;
    pair<int, int> rank;
    bool operator<(Suffix r) {
        return rank < r.rank;
    }
};

vector<Suffix> sa(string a) {
    vector<Suffix> ans(a.size());
    vector<Suffix *> whereis(a.size());
    for (int i = 0; i < a.size(); ++i) {
        ans[i].i = i;
        ans[i].rank.first = a[i];
        ans[i].rank.second = a[i + 1];
    }
    sort(ans.begin(), ans.end());
    for (int k = 2; k < a.size(); k *= 2) {
        pair<int, int> prevrank = ans[0].rank;
        int rank = 0;
        ans[0].rank.first = rank;
        for (int i = 0; i < a.size(); ++i) {
            if (ans[i].rank != prevrank) {
                ++rank;
                prevrank = ans[i].rank;
            }
            ans[i].rank.first = rank;
            whereis[ans[i].i] = &ans[i];
        }
        for (int i = 0; i < a.size(); ++i) {
            if (ans[i].i + k < whereis.size()) {
                ans[i].rank.second = whereis[ans[i].i + k]->rank.first;
            } else {
                ans[i].rank.second = -1;
            }
        }
        sort(ans.begin(), ans.end());
    }
    return ans;
}

int main() {
    string s = "abacaba";
    for (Suffix ss : sa(s)) {
        cout << s.substr(ss.i) << endl;
    }
}
