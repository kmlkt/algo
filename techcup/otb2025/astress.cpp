#include <cmath>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const bool even(const char &c) {
    return (c - '0') % 2 == 0;
}

ll notsress(ll ss) {
    string s = to_string(ss);
    ll ans = 0;
    ans += s.size() - 1;
    if (even(s[s.size() - 1])) {
        for(int i = 0; i < s.size() - 1; ++i) {
            if(even(s[i])) {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    ll s;
    cin >> s;
    ll l = s;
    ll ans = 0;
    ll r = 0;
    int i = 0;
    while (l != 0){
        r += (l % 10) * pow(10, i);
        l /= 10;
        if(l == 0) {
            break;
        }
        if((l * r) % 2 == 0) {
            ++ans;
        }
        if((l + r) % 2 == 0) {
            ++ans;
        }
        ++i;
    }
    cout << ans << ":" << notsress(s);
}
