#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, x; cin >> n >> x;

        bool fg = true;
        for (int i = 0, p = -1; i < n; ++ i) {
            int t; cin >> t; if (p == -1) p = t;
            if (fg && i && (t - p > 1 || p - t > x)) fg = false; 
            p = t;
        }

        cout << (fg ? "Win" : "Lose") << '\n';
    }
    return 0;
}