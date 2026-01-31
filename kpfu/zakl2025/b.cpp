#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string center = "";
    if (n % 2) {
        center = s[n / 2];
        s = s.substr(0, n / 2) + s.substr(n / 2 + 1, n);
        --n;
    }
    int have = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            ++have;
        }
    }
    if (have > k) {
        for (int i = 0; i < n; ++i) {
            if (s[i] != s[n - 1 - i]) {
                if (s[i] > s[n - 1 - i]) {
                    s[i] = s[n - 1 - i];
                    --have;
                    if (have == k) {
                        break;
                    }
                }
            }
        }
    }
    if (have < k) {
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == s[n - 1 - i]) {
                if (s[n - 1 - i] != 'a') {
                    s[i] = 'a';
                    ++have;
                    if (have == k) {
                        break;
                    }
                }
            }
        }
        if (have < k) {
            for (int i = 0; i < n / 2; ++i) {
                if (s[i] == s[n - 1 - i]) {
                    if (s[n - 1 - i] == 'a') {
                        s[n - 1 - i] = 'b';
                        ++have;
                        if (have == k) {
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << s.substr(0, n / 2) + center + s.substr(n / 2, n);
}
