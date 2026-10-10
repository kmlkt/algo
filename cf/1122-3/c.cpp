#include <algorithm>
#include <cstdint>
#include <float.h>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

string s;
vector<bool> a;

ll solve() {
    int n;
    cin >> n;
    cin >> s;
    a.resize(n);
    for(int i = 0; i < n; ++i) {
        a[i] = s[i] == '1';
    }
    if(count(a.begin(), a.end(), 0) == 0 || count(a.begin(), a.end(), 1) == 0) {
        return 0;
    }
    if(a[0] == 1) {
        return count(a.begin(), a.end(), 0);
    }
    int l = 0;
    while(a[l] != 1) {
        ++l;
    }
    int ones_left = 0;
    int zeros_right = count(a.begin() + l, a.end(), 0);
    int opt = INT32_MAX;
    for(int i = l; i <= n; ++i) {
        opt = min(opt, ones_left + zeros_right);
        if(i < n) {
            if(a[i] == 1) {
                ones_left += 1;
            } else {
                zeros_right -= 1;
            }
        }
    }
    return opt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
