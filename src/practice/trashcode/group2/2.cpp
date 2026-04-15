#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, H; cin >> n >> m >> H;

    vector<int> h(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> h[i];

    vector<vector<pii>> g(n + 1);
    for (int i = 0; i < m; ++ i) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c}); g[b].push_back({a, c});
    }

    vector<int> a(n + 1, 1e18);
    auto dijkstra = [&](int s) -> void {
        vector<vector<int>> dist(n + 1, vector<int>(H + 1, 1e18)); dist[s][0] = 0;

        priority_queue<tiii, vector<tiii>, greater<tiii>> heap; heap.push({0, s, 0});
        while (heap.size()) {
            auto [dis, u, nh] = heap.top(); heap.pop();

            for (auto [v, w] : g[u]) {
                auto t = nh + h[v] - h[u];
                if (t > H) continue;
                if (h[u] > h[v] && dist[v][0] > dist[u][nh] + w) dist[v][0] = dist[u][nh] + w, heap.push({dist[v][0], v, 0});
                else if (h[u] <= h[v] && dist[v][t] > dist[u][nh] + w) dist[v][t] = dist[u][nh] + w, heap.push({dist[v][t], v, t});
            }
        }

        for (int i = 2; i <= n; ++ i) for (int j = 0; j <= H; ++ j) a[i] = min(a[i], dist[i][j]);
    };

    dijkstra(1);

    for (int i = 2; i <= n; ++ i) cout << (a[i] == 1e18 ? -1 : a[i]) << " \n"[i == n];
    return 0;
}