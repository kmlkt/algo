#include <iostream>
#include <map>

using namespace std;
using ll = long long;

map<int, int> cache;

int INF = 1e8;

int check(int n, int k) {
    if (n < k) {
        return INF;
    }
    if (n == k) {
        return 0;
    }
    if (cache.find(n) != cache.end()) {
        return cache[n];
    }
    int &ans = cache[n] = check(n / 2, k) + 1;
    if (n % 2) {
        ans = min(ans, check(n / 2 + 1, k) + 1);
    }
    return ans;
}

int solve() {
    cache.clear();
    int n, k;
    cin >> n >> k;
    int ans = check(n, k);
    if (ans >= INF) {
        ans = -1;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
