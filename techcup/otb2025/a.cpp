#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const bool even(const char &c) {
    return (c - '0') % 2 == 0;
}

int main() {
    string s;
    cin >> s;
    ll ans = 0;
    ans += s.size() - 1;
    if (even(s[s.size() - 1])) {
        for(int i = 0; i < s.size() - 1; ++i) {
            if(even(s[i])) {
                ++ans;
            }
        }
    }
    cout << ans;
}
