#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));

        for (auto &E : a) for (auto &e : E) cin >> e;

        for (int i = 0; i < n; ++ i) sort(a[i].begin(), a[i].end());

        int t = -1; bool fg = true;
        for (int i = 0; i < n; ++ i) {
            auto p = lower_bound(a[i].begin(), a[i].end(), t + 1);

            if (p != a[i].end()) t = *p;
            else { fg = false; break; }
        }

        cout << (fg ? "YES" : "NO") << '\n';
    }
    return 0;
}