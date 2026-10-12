#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

ll solve() {
    string aniso = "256890";
    int N = 11;
    string s;
    cin >> s;
    int n = s.size();

    for(char c : s) {
        if(count(aniso.begin(), aniso.end(), c) == 0) {
            return 0;
        }
    }
    if(n <= 5) {
        int cnt = (N - 1) / 2 - n;
        return pow(6L, cnt) * 4L;
    } else {
        for(int i = 0; i < n; ++i) {
            if(N - 1 - i < n) {
                char c = s[i];
                char r = s[N - 1 - i];
                if(c == '2' && r == '2' || c == '5' && r == '5' || c == '6' && r == '9'
                    || c == '9' && r == '6' || c == '8' && r == '8' || c == '0' && r == '0') {
                    // ok
                } else {
                    return 0;
                }
            }
        }
        return 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve();
}
