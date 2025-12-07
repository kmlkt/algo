#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
string a;

bool pal(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool repeats(int r) {
    for (int i = r; i < a.size(); ++i) {
        if (a[i] != a[i - r]) {
            return false;
        }
    }
    return true;
}

vector<int> del(int n) {
    vector<int> ans;
    ans.push_back(1);
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
        while (n % i == 0) {
            n /= i;
        }
    }
    return ans;
}

int main() {
    cin >> a;
    auto d = del(a.size());
    for (int i = 1; i <= a.size(); ++i) {
        string si = a.substr(0, i);
        if (!pal(si)) {
            continue;
        }
        if (!pal(a + si)) {
            continue;
        }
        cout << si;
        return 0;
    }
}
