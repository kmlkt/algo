#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll d, m, w, i, j, k;
    cin >> d >> m >> w >> i >> j >> k;
    --i;
    --j;
    --k;
    ll glob = i + j * d + k * d * m;
    ll ned = glob % w;
    cout << (char)('a' + ned);
}
