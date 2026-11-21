#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using ll = long long;


int main() {
    int m, n, p, k, s;
    cin >> m >> n >> p >> k >> s;
    vector<vector<char>> seen(m, vector<char>(n));
    vector<vector<bool>> a(m, vector<bool>(n));
    for(int i = 0; i < s; ++i) {
        int r, c;
        char x;
        cin >> r >> c >> x;
        --r;
        --c;
        if(seen[r][c] && seen[r][c] != x) {
            a[r][c] = 1;
        } else {
            seen[r][c] = x;
        }
    }
    vector<vector<int>> gaps(m);
    vector<vector<int>> gap_starts(m);
    for(int r = 0; r < m; ++r) {
        int gap = 0;
        for(int c = 0; c < n; ++c) {
            if(a[r][c]) {
                gaps[r].push_back(gap);
                gap_starts[r].push_back(c - gap);
                gap = 0;
            } else {
                ++gap;
            }
        }
        gaps[r].push_back(gap);
        gap_starts[r].push_back(n - gap);
    }
    int options = 0;
    bool amb = 0;
    for(int r = 0; r < m; ++r) {
        for(int gap : gaps[r]) {
            if(gap >= k) {
                options += gap / k;
                if(gap % k) {
                    amb = 1;
                }
            }
        }
    }
    if(options < p) {
        cout << "impossible";
    } else if(options > p || amb) {
        cout << "ambiguous";
    } else {
        cout << "unique\n";
        for(int r = 0; r < m; ++r) {
            for(int i = 0; i < gaps[r].size(); ++i) {
                if(gaps[r][i] >= k) {
                    int start = gap_starts[r][i];
                    for(int j = 0; j < gaps[r][i] / k; ++j) {
                        cout << r + 1 << ' ' << start + 1 << '\n';
                        start += k;
                    }
                }
            }
        }
    }
}
