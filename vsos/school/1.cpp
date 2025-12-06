#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    int r = a / 4;
    int n = b + (r + 1) * 2;
    int ans = n / 6;
    cout << ans;
}
