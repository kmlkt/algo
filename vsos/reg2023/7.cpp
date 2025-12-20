#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
vector<int> a;
vector<int> c;

int main() {
    cin >> n >> m;
    a.resize(n);
    c.resize(m + 1);
    for (int &ai : a) {
        cin >> ai;
        ++c[ai];
    }
    for(int i = 1; i <= m; ++i) {
        
    }
}
