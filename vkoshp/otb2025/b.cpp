#include <iostream>
using namespace std;
;
int main() {
    int n;
    cin >> n;
    int H = 0;
    int W = 0;
    // W >= H
    for (int i = 0; i < n; ++i) {
        int w, h;
        cin >> w >> h;
        if (h > w) {
            swap(w, h);
        }
        W = max(W, w);
        H = max(H, h);
    }
    cout << H << " " << W;
}
