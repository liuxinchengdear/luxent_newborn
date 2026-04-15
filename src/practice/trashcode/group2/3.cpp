#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> g(n + 1);

    for (int i = 2; i <= n; ++ i) {
        int x; cin >> x;
        g[x].push_back(i);
    }

    vector<int> p(n + 1);
    auto dfs = [&](auto &&dfs, int u) -> int {
        p[u] = 1;
        for (auto v : g[u]) p[u] += dfs(dfs, v);
        return p[u];
    };

    dfs(dfs, 1);

    int res = 0;
    auto dfs = [&](auto &&dfs, int u, int t) -> int {
        vector<pii> a;
        for (auto v : g[u]) a.push_back({p[v], v});
        sort(a.begin(), a.end(), greater<pii>());

        int sum = a.size() ? 2 : 1;
        for (int i = 2; i < a.size(); ++ i) {
            
        }
    };
}