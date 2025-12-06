#include <algorithm>
#include <cmath>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int complexity = 0;

vector<int> n(string a) {
    vector<int> ans(a.size());
    auto ultraright = 0;
    for (int i = 1; i < ans.size(); ++i) {
        ans[i] = max(0, min(ans[i - ultraright], ultraright + ans[ultraright] - i));
        cout << i << ':' << ans[i] << "...";
        while (i + ans[i] < a.size() && a[i + ans[i]] == a[ans[i]]) {
            ++ans[i];
            ++complexity;
        }
        if (i + ans[i] > ultraright + ans[ultraright]) {
            ultraright = i;
        }
        cout << ans[i] << ',' << ultraright << endl;
    }
    return ans;
}

int main() {
    for (int ni : n("abacaba")) {
        cout << ni << ' ';
    }
    cout << endl;
    cout << complexity;
}
