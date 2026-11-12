#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<int> st;
    vector<bool> p(n, false);
    for(int i = 0; i < n; ++i) {
        switch (s[i]) {
        case '1':
            st.push(i);
            break;
        case '2':
            if(!st.empty()) {
                p[st.top()] = 1;
                st.pop();
                break;
            }
        case '3':
            p[i] = 1;
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; ++i) {
        if(!p[i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for(int ansi : ans) {
        cout << ansi + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
