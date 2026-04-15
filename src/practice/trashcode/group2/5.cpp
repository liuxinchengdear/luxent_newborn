#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        bool fg = false; int ans = -1;
        for (int i = 1; i < 2 * n - 2; i += 2) {
            cout << "? " << i << " " << i + 1 << endl;
            int x; cin >> x;
            if (x == 1) { fg = true; ans = i; break; }
        }

        if (!fg) {
            cout << "? " << 2 * n - 2 << " " << 2 * n << endl;
            int x; cin >> x;
            cout << "? " << 2 * n - 3 << " " << 2 * n << endl;
            int y; cin >> y;
            ans = (x || y ? 2 * n : 2 * n - 1);
        }

        cout << "! " << ans << endl;
    }
    return 0;
}