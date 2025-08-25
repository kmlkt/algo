#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    vector<int> k(q);
    for (int &ki : k) {
        cin >> ki;
    }
    sort(k.begin(), k.end());
    int a_iter = 0;
    int k_iter = 0;
    int ans = 0;
    for (int i = 0; k_iter != k.size(); ++i) {
        if (a[a_iter] == i) {
            ++a_iter;
        } else {
            ++ans;
        }
        if (k[k_iter] == ans) {
            cout << i << ' ';
            ++k_iter;
        }
    }
}
