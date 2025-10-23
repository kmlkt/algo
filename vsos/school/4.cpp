#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    string s;
    int t, n;
    cin >> s >> t >> n;
    ll ans = 0;
    vector<string> keyboard{
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    int prevbtn = -1;
    for (char c : s) {
        for (int btn = 0; btn < keyboard.size(); ++btn) {
            int taps = keyboard[btn].find(c);
            if (taps == keyboard[btn].npos) {
                continue;
            }
            taps++;
            ans += taps * n;
            if (btn == prevbtn) {
                ans += min(t, 2 * n);
            }
            prevbtn = btn;
        }
    }
    cout << ans;
}
