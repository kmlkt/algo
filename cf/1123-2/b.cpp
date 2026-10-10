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

vector<int> a;
vector<int> b;
map<int, int> cnt;

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for(int &ai : a) {
        cin >> ai;
        ++cnt[-ai];
    }
    b.clear();
    for(;;) {
        bool any = false;
        for(auto &[x, c] : cnt) {
            if(c != 0) {
                any = true;
                b.push_back(-x);
                --c;
            }
        }
        if(!any) {
            break;
        }
    }
    for(int &bi : b) {
        cout << bi << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
