#include <algorithm>
#include <array>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 2e5;
int b1[N];
int b2[N];

int main() {
    int n;
    cin >> n;
    string s;
    int *cur = b1;
    int *buf = b2;
    int *sorted = nullptr;
    int sorted_size = 0;
    int *unsorted = cur;
    int unsorted_size = 0;
    while (n--) {
        cin >> s;
        switch (s[0]) {
        case 't':
            int x;
            cin >> x;
            unsorted[unsorted_size] = x;
            ++unsorted_size;
            break;
        case 'm':
            if (unsorted == cur) {
                cout << unsorted[0];
                ++unsorted;
                --unsorted_size;
            } else {
                cout << sorted[0];
                ++sorted;
                --sorted_size;
                if (sorted_size == 0) {
                    sorted = nullptr;
                }
            }
            cout << '\n';
            ++cur;
            break;
        case 'l':
            sort(unsorted, unsorted + unsorted_size);
            merge(
                sorted, sorted + sorted_size,
                unsorted, unsorted + unsorted_size,
                buf);
            swap(cur, buf);
            sorted = cur;
            sorted_size += unsorted_size;
            unsorted = cur + sorted_size;
            unsorted_size = 0;
            if (sorted_size == 0) {
                sorted = nullptr;
            }
            break;
        }
    }
}
