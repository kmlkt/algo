#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int last(vector<int> &v) {
    return v[v.size() - 1];
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> start(n);
    vector<vector<int>> end(n);
    vector<int> start_of(q);
    vector<int> end_of(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        if (l > r) {
            swap(l, r);
        }

        start_of[i] = l;
        end_of[i] = r;

        start[l].push_back(i);
        end[r].push_back(i);
    }
    for (int x = 0; x < n; ++x) {
        sort(start[x].begin(), start[x].end(),
             [&end_of](int l, int r) {
                 return end_of[l] > end_of[r];
             });
        sort(end[x].begin(), end[x].end(),
             [&start_of](int l, int r) {
                 return start_of[l] > start_of[r];
             });
    }
    vector<int> st;
    st.reserve(q);
    for (int x = 0; x < n; ++x) {
        for (int i : end[x]) {
            if (i != last(st)) {

                cout << "discard";
                return 0;
            }
            st.pop_back();
        }
        for (int i : start[x]) {
            st.push_back(i);
        }
    }
    cout << "approve";
}
