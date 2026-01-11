#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int &ai : a) {
        cin >> ai;
        sum += ai;
    }
    int mid = (sum + n / 2) / n;
    int take = 0;
    int give = 0;
    for (int ai : a) {
        if (ai > mid) {
            take += ai - mid;
        } else {
            give += mid - ai;
        }
    }
    int ans = max(take, give);
    cout << ans;
}
