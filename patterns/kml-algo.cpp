#include <cmath>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

int n = 10;
vector<int> a{2, 3, 4, 5, 1, 2, 3, 1, -1, 4};
vector<vector<int>> tree;

int max_2(int x) {
    return (x & (~(x - 1)));
}

struct left_interval {
    int ans;
    int r;
};

left_interval find_left_interval(int l, int r) {
    cout << "Рассмотрим интервал [" << l << ", " << r << ")" << endl;
    int hp = max_2(l);
    if (l == 0) {
        hp = 1 << tree.size();
    }
    cout << "Максимальная длина отрезка с началом в " << l << ": " << hp << endl;
    while (l + hp > r) {
        cout << "Отрезок заходит за правую границу. Уменьшим его" << endl;
        hp >>= 1;
        cout << "Новая длина " << hp << endl;
    }
    cout << "Найдём максимум на интервале [" << l << ", " << l + hp << ")" << endl;
    int i = log2(hp);
    int j = l / hp;
    int ans = tree[i][j];
    cout << "Максимум лежит в дереве в {" << i << ", " << j << "} и равняется " << ans << endl
         << endl;
    return left_interval{ans, l + hp};
}

int find_max(int l, int r) {
    cout << "Поиск максимума" << endl;
    int ans = INT32_MIN;
    r += 1;
    while (l < r) {
        auto li = find_left_interval(l, r);
        ans = max(ans, li.ans);
        l = li.r;
    }
    return ans;
}

int main() {
    cout << "Алгоритм Камалетдинова" << endl;
    cout << "Оптимизированная реализация дерева отрезков" << endl;
    int height = ceil(log2(n));
    tree = vector<vector<int>>(height + 1);
    tree[0] = a;
    for (int i = 1; i <= height; ++i) {
        tree[i] = vector<int>(ceil(tree[i - 1].size() / 2.0));
        for (int j = 0; j < tree[i].size() - tree[i - 1].size() % 2; ++j) {
            tree[i][j] = max(tree[i - 1][j * 2], tree[i - 1][j * 2 + 1]);
        }
        if (tree[i - 1].size() % 2) {
            tree[i][tree[i].size() - 1] = tree[i - 1][tree[i - 1].size() - 1];
        }
    }
    cout << "Полученное ДО" << endl;
    for (int i = 0; i <= height; ++i) {
        for (int x : tree[i]) {
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << find_max(0, 9) << endl;
}
