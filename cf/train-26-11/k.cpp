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


void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ri = s.find("R");
    int ci = s.find("C");
    if(ri == 0 && ci != -1 && '0' <= s[1] && s[1] <= '9') {
        int r = stoi(s.substr(1, ci - 1));
        int c = stoi(s.substr(ci + 1));
        int ct = c;
        string cs = "";
        do {
            ct--;
            cs += ('A' + (ct) % 26);
            ct /= 26;
        } while(ct > 0);
        reverse(cs.begin(), cs.end());
        cout << cs << r << '\n';
    } else {
        string cs = "";
        string rs = "";
        for(char x : s) {
            if('0' <= x && x <= '9') {
                rs += x;
            } else {
                cs += x;
            }
        }
        int r = stoi(rs);
        int c = 0;
        for(char x : cs) {
            c *= 26;
            c += (x - 'A' + 1);
        }
        cout << 'R' << r << 'C' << c << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
