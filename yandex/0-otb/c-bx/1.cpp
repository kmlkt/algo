#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    vector<vector<bool>> r(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        int l;
        cin >> l;
        for (int k = 0; k < l; ++k) {
            int rk;
            cin >> rk;
            r[i][rk - 1] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            // Pi < Pj
            if (c[i] > c[j])
                continue;
            bool ansI = c[i] > c[j];
            for (int k = 0; k < m; ++k) {
                if (r[i][k] < r[j][k]) {
                    ansI = false;
                    break;
                }
                ansI = r[i][k] > r[j][k];
            }
            if (ansI) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}
