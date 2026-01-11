#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int pm = 0;
    for (int i = 1; i < n; ++i) {
        int ai;
        cin >> ai;
        if (ai >= m) {
            pm = m;
            m = ai;
        } else if (ai >= pm) {
            pm = ai;
        }
        cout << pm << ' ';
    }
}
