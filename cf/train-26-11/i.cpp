#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;



int main() {
    int n, m;
    char c;
    cin >> n >> m >> c;
    vector<string> a(n);
    for(string &ai : a) {
        cin >> ai;
    }
    set<char> s;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(a[i][j] == c) {
                if(i > 0) {
                    s.insert(a[i-1][j]);
                }
                if(i < n - 1) {
                    s.insert(a[i+1][j]);
                }
                if(j > 0) {
                    s.insert(a[i][j-1]);
                }
                if(j < m - 1) {
                    s.insert(a[i][j+1]);
                }
            }
        }
    }
    s.erase(c);
    s.erase('.');
    cout << s.size();
}
