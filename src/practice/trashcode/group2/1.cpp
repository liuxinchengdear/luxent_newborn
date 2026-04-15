#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, H; cin >> n >> m >> H;

    vector<int> h(n + 1); 
    for (int i = 1; i <= n; ++ i) cin >> h[i];

    vector<vector<pii>> g((H + 1) * (n + 1) + 1);

    auto process = [&](int a, int b, int c) -> void {
        auto help = [&](int a, int b, int c, int k) -> void {
            if (h[a] > h[b]) g[a + k * (n + 1)].push_back({b, c});
            else if (h[a] < h[b] && (k + h[b] - h[a] <= H)) g[a + k * (n + 1)].push_back({b + (k + h[b] - h[a]) * (n + 1), c}); 
            else if (h[a] == h[b]) g[a + k * (n + 1)].push_back({b + k * (n + 1), c});
        };

        for (int i = 0; i <= H; ++ i) help(a, b, c, i), help(b, a, c, i);
    };

    for (int i = 0; i < m; ++ i) {
        int a, b, c; cin >> a >> b >> c;
        
        process(a, b, c);
    }

    vector<int> a(n + 1, 1e18);

    auto dijkstra = [&](int s) -> void {
        vector<int> dist((H + 1) * (n + 1) + 1, 1e18); dist[s] = 0;
        vector<int> st((H + 1) * (n + 1) + 1);

        priority_queue<pii, vector<pii>, greater<pii>> heap; heap.push({0, s});

        while (heap.size()) {
            auto [dis, u] = heap.top(); heap.pop();
            if (st[u]) continue; st[u] = true;
            for (auto [v, w] : g[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    heap.push({dist[v], v});
                }
            }
        }

        for (int i = 0; i <= H; ++ i) {
            for (int u = 1; u <= n; ++ u) a[u] = min(a[u], dist[u + i * (n + 1)]);
        }
    };

    dijkstra(1);

    for (int i = 2; i <= n; ++ i) cout << (a[i] == 1e18 ? -1 : a[i]) << " \n"[i == n];
    return 0;
}