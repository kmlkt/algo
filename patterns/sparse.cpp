#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

int n = 10;
vector<int> a{2, 3, 4, 5, 1, 2, 3, 1, -1, 4};
vector<vector<int>> table;

int find_max(int l, int r) {
    r += 1;
    int dist = r - l;
    int lg2 = floor(log2(dist));
    int take = 1 << lg2;
    cout << "TAKE " << take << endl;
    int level = lg2;
    cout << "LEVEL " << level << endl;
    return max(table[level][l], table[level][r - take]);
}

int main() {
    int height = ceil(log2(n));
    table = vector<vector<int>>(height + 1);
    table[0] = a;
    for (int i = 1; i <= height; ++i) {
        int _2i = 1 << (i - 1);
        table[i] = vector<int>(ceil(table[i - 1].size() - _2i));
        for (int j = 0; j < table[i].size(); ++j) {
            table[i][j] = max(table[i - 1][j], table[i - 1][j + _2i]);
        }
    }
    for (int i = 0; i <= height; ++i) {
        for (int x : table[i]) {
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << find_max(9, 9);
}
