#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r, c, mo;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> a(105);
    for (int i = 0; i < n; ++ i) {
        int l, r, c; cin >> l >> r >> c;
        for (int j = l; j <= r; ++ j) {
            a[j] = max(a[j], c);
        }
    }

    vector<Node> g(m);

    for (int i = 0; i < m; ++ i) {
        auto &[l, r, c, mo] = g[i];
        cin >> l >> r >> c >> mo;
    }

    int res = 1e9;
    for (int i = 0; i < 1 << m; ++ i) {
        vector<int> t;
        for (int j = 0; j < m; ++ j) {
            if (i >> j & 1) t.push_back(j);
        }

        int sum = 0;
        vector<int> na(105);
        for (auto e : t) {
            auto [l, r, c, mo] = g[e]; sum += mo;
            for (int j = l; j <= r; ++ j) na[j] += c;
        }

        bool fg = true;
        for (int i = 1; i <= 100; ++ i) if (na[i] < a[i]) { fg = false; break; }

        if (fg) res = min(res, sum);
    }
    cout << (res == 1e9 ? -1 : res) << '\n';
    return 0;
}