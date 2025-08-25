#include <algorithm>
#include <cmath>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

vector<int> prefix(string a) {
    vector<int> ans(a.size());
    for (int i = 1; i < ans.size(); ++i) {
        int compared = i - 1;
        while (true) {
            if (a[i] == a[ans[compared]]) {
                ans[i] = max(0, ans[compared]) + 1;
                break;
            }
            if (compared == 0) {
                break;
            }
            compared = ans[compared] - 1;
        }
    }
    return ans;
}

int main() {
    for (int ni : prefix("abacaba")) {
        cout << ni << ' ';
    }
}
