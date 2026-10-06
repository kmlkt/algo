#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for(int &bi : b) {
        cin >> bi;
    }
    for(int &bi : b) {
        if(bi == -1) {
            bi = 1;
        }
        if(bi == 1) {
            break;
        }
    }
    reverse(b.begin(), b.end());
    for(int &bi : b) {
        if(bi == -1) {
            bi = 1;
        }
        if(bi == 1) {
            break;
        }
    }
    reverse(b.begin(), b.end());
    for(int &bi : b) {
        if(bi == -1) {
            bi = 0;
        }
    }
    for(int bi : b) {
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
