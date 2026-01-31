#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct jump {
    ll a, b, c, p;
};

vector<jump> j;

ll solve() {
    int n;
    ll x;
    cin >> n >> x;
    j.resize(n);
    ll free = 0;
    ll bestP = 0;
    for (jump &ji : j) {
        cin >> ji.a >> ji.b >> ji.c;
        ji.p = ji.a * ji.b - ji.c;
        free += ji.a * (ji.b - 1);
        bestP = max(bestP, ji.p);
    }
    if (free >= x) {
        return 0;
    }
    if (bestP == 0) {
        return -1;
    }
    return (x - free - 1) / bestP + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
