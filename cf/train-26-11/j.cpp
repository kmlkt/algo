#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void build_can_begin(string &s, string &p, vector<char> &b) {
    for(int i = 0; i + p.size() <= s.size(); ++i) {
        b[i] = 1;
        for(int j = 0; j < p.size(); ++j) {
            if(s[i+j] != p[j]) {
                b[i] = 0;
                break;
            }
        }
    }
}

bool solve(string &s, string &p1, string &p2) {
    int n = s.size();
    vector<char> b1(n), b2(n);
    build_can_begin(s, p1, b1);
    build_can_begin(s, p2, b2);
    int leftest_b1 = n;
    int rightest_b2 = -1;
    for(int i = 0; i < n; ++i) {
        if(b1[i]) {
            leftest_b1 = min(leftest_b1, i);
        }
        if(b2[i]) {
            rightest_b2 = max(rightest_b2, i);
        }
    }
    return leftest_b1 + (int)p1.size() <= rightest_b2;
}

int main() {
    string s, p1, p2;
    cin >> s >> p1 >> p2;
    bool forward = solve(s, p1, p2);
    reverse(s.begin(), s.end());
    bool backward = solve(s, p1, p2);
    if(forward && backward) {
        cout << "both";
    } else if(forward) {
        cout << "forward";
    } else if(backward) {
        cout << "backward";
    } else {
        cout << "fantasy";
    }
}
