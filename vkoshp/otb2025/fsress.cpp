#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
;
int main() {
    bitset<1000> dp;
    for (int i = 2; i < 1000; ++i) {
        for (int k = 2; k < i; ++k) {
            if (i % k == 0) {
                int l = i - k;
                if (dp[k] == dp[l]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    cout << dp;
}
