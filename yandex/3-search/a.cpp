#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a;

bool check(int dist) {
    int pos = a[0];
    int cows = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] - pos >= dist) {
            ++cows;
            pos = a[i];
        }
    }
    return cows >= k;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int &ai : a) {
        cin >> ai;
    }
    int l = 1;       // check(l) = true
    int r = 1e9 + 5; // check(r) = false
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l;
}
