#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, q; cin >> n >> m >> q;

        vector<vector<pii>> g(n + 1);

        for (int i = 0; i < m; ++ i) {
            int x, y, d; cin >> x >> y >> d;
            g[x].push_back({y, d}); g[y].push_back({x, d});
        }

        vector<int> p(n + 1, 1);

        for (int i = 1; i <= n; ++ i) {
            for (auto [v, w] : g[i]) {
                p[i] = lcm(p[i], w);
            }
        }

        while (q -- ) {
            int x, y; cin >> x >> y;

            cout << gcd(p[x], p[y]) << '\n';
        }
    }
    return 0;
}