#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int last(vector<int> &a) {
    if (a.size() == 0) {
        return -1;
    }
    return a[a.size() - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    reverse(a.begin(), a.end());
    vector<int> t;
    int cur = 1;
    vector<int> ans;
    while (a.size() || t.size()) {
        if (last(t) == cur) {
            ans.push_back(2);
            t.pop_back();
            ++cur;
        } else {
            if (a.empty()) {
                break;
            }
            ans.push_back(1);
            t.push_back(last(a));
            a.pop_back();
        }
    }
    if (cur == n + 1) {
        cout << ans.size() << "\n";
        for (int &ansi : ans) {
            cout << ansi << " 1\n";
        }
    } else {
        cout << "0";
    }
}
