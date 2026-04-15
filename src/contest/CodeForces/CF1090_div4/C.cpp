#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int l = 1, r = 3 * n;
        for (int i = 0; i < n; ++ i) {
            cout << l ++ << " " << r - 1 << " " << r << " "; r -= 2;
        } cout << '\n';
    }
    return 0;
}