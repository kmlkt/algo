#include <bitset>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>

using namespace std;
using ll = long long;

string s;

int is3(int l, int r) {
    ll x = 0;
    for(int i = l; i < r; ++i) {
        x <<= 1;
        x += s[i] - '0';
    }
    return x % 3;
}

int is3o(int l, int r) {
    ll x = 0;
    int i = r - 1;
    for(; i > l; i -= 2) {
        int p = (s[i] - '0') + (s[i - 1] - '0') * 2;
        x += p;
    }
    if(i == l) {
        x += s[i] - '0';
    }
    return x % 3;
}

void solve() {
    int l = 1, r = s.size();
    //cin >> l >> r;
    --l;
    ll ans = 0;
    for(int i = l; i < r - 1; ++i) {
        swap(s[i], s[i + 1]);
        if(is3(l, r)){
            ++ans;
        }
        swap(s[i], s[i + 1]);
    }
    cout << ans << "\n";
}

int main() {
    char * c = new char[100];
    for(int i = 0; i < 1000; ++i) {
        itoa(i, c, 2);
        cout << c << ":\t";
        s = c;
        cout << is3(0, s.size()) << ":"
        << is3o(0, s.size()) << "\n";
    }
}
