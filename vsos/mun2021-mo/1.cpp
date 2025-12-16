#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int l, d, k;
    cin >> l >> d >> k;
    int ans1 = l / d;
    int ans2 = (l % d == 0) ? k : k - 1;
    cout << min(ans1, ans2);
}
