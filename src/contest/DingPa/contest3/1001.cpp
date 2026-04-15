#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;

        multiset<int, greater<int>> a, b;
        for (int i = 1, x; i <= n; ++ i) cin >> x, a.insert(x);

        for (int i = 1, x; i <= n + 1; ++ i) cin >> x, b.insert(x);

        auto eval = [&](int x) -> bool {
            vector<int> na(n + 1);
            auto t = a.insert(x); int ix = -1;
            for (auto e : a) na[ ++ ix] = e; a.erase(t);
            int ans = 0; ix = -1;
            for (auto e : b) {
                ans += e * na[ ++ ix];
                if (ans >= m) return true;
            }
            return false;
        };

        if (eval(0)) { cout << 0 << '\n'; continue; }

        auto bi = [&](int l, int r) -> double {
            while (l < r) {
                int mid = l + r >> 1;
                if (eval(mid)) r = mid;
                else l = mid + 1;
            }
            return r;
        };

        cout << bi(1, m) << '\n';
    }
    return 0;
}