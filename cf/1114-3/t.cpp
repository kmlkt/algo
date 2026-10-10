#include <algorithm>
#include <iostream>
using namespace std;

void reverse(int n) {
    if(n == 0) {
        return;
    }
    int ai;
    cin >> ai;
    reverse(n - 1);
    cout << ai << ' ';
}

int main() {
    int n;
    cin >> n;
    reverse(n);
}
