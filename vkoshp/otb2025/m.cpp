#include <iostream>
using namespace std;

int main() {
    int prev = 0;
    int prevdelta = 0;
    for (int n = 200; n < 201; ++n) {
        int ans = 0;
        // f(n + 1) - f(n)
        for (int i = 1; i < n + 1; i++) {
            int dans = 0;
            for (int j = 1; j < n + 1; j++) {
                dans += i % j;
                cout << i % j << " ";
            }
            cout << "|" << dans;
            ans += dans;
            cout << "\n";
        }
        int delta = (ans - prev);
        cout << n << ": " << ans << "; " << delta << "; " << (delta - prevdelta) << "\n";
        prevdelta = delta;
        prev = ans;
    }
}
