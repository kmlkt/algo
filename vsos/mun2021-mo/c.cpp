#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct coder {
    int age;
    int zeros;
    int ones;

    bool operator<(coder another) {
        return zeros > another.zeros;
    }
};

int main() {
    int n;
    cin >> n;
    vector<coder> c(n);
    for (coder &ci : c) {
        cin >> ci.age;
        for (int j = 1; j <= ci.age; j <<= 1) {
            if ((j & ci.age) == 0) {
                ++ci.zeros;
            } else {
                ++ci.ones;
            }
        }
    }
    sort(c.begin(), c.end());
    int ans = 0;
    int zeros = 0;
    for (coder ci : c) {
        int need = ci.ones + ci.zeros;
        int take = min(need, zeros);
        need -= take;
        zeros -= take;
        zeros += ci.zeros;
        ans += need;
    }
    cout << ans;
}
