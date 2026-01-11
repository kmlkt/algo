#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());
    int b = a[0];
    int s = a[1];
    int t = a[a.size() - 1];
    int ans = max(0, (b + s) - (t - b) - 1);
    cout << ans;
}
