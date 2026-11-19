#include <algorithm>
#include <array>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int N = 1 << 21;
array<int, N> previ;
array<int, N> curr;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1)));
    dp[0][0][0] = 0;
    for (int threes = 0; threes <= n; ++threes) {
        for (int twos = 0; threes + twos <= n; ++twos) {
            for (int ones = 0; threes + twos + ones <= n; ++ones) {
                if (ones == 0 && twos == 0 && threes == 0) {
                    continue;
                }
                dp[ones][twos][threes] = 1.0 * n;
                if (ones > 0) {
                    dp[ones][twos][threes] += 1.0 * ones * dp[ones - 1][twos][threes];
                }
                if (twos > 0) {
                    dp[ones][twos][threes] += 1.0 * twos * dp[ones + 1][twos - 1][threes];
                }
                if (threes > 0) {
                    dp[ones][twos][threes] += 1.0 * threes * dp[ones][twos + 1][threes - 1];
                }
                dp[ones][twos][threes] /= 1.0 * (ones + twos + threes);
            }
        }
    }
    cout << setprecision(20) << dp[count(a.begin(), a.end(), 1)][count(a.begin(), a.end(), 2)][count(a.begin(), a.end(), 3)];
}
