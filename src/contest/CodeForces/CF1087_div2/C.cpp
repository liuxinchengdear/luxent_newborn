    #include <bits/stdc++.h>
    using namespace std;

    signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int _T; cin >> _T; while (_T -- ) {
            int n; cin >> n;

            int ans = -1;
            for (int i = 1; i < n && ans == -1; ++ i) {
                cout << "? " << 2 * i + 1 << " " << 2 * i + 2 << endl;
                int x; cin >> x;
                if (x) ans = 2 * i + 1;
            }

            if (ans == -1) {
                cout << "? 1 3" << endl; int x; cin >> x;
                cout << "? 1 4" << endl; int y; cin >> y;

                ans = x || y ? 1 : 2;
            }

            cout << "! " << ans << endl;
        }
        return 0;
    }