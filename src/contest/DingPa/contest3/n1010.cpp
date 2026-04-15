#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, N = 5010;

int c[N + 1][N + 1];
vector<pair<int, int>> adj[2010]; 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 预处理组合数
    for (int i = 1; i <= N; ++i) c[i][1] = c[i][i] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 2; j < i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;

    int _T; cin >> _T;
    while (_T--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        for (int i = 1; i <= n; ++i) adj[i].clear();

        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int w = c[max(a[i], a[j]) + 1][min(a[i], a[j]) + 1];
                adj[i].emplace_back(j, w);
                adj[j].emplace_back(i, w);
            }
        }

        auto prim = [&]() -> int {
            vector<int> dist(n + 1, 1e9);
            vector<bool> st(n + 1);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

            dist[1] = 0;
            q.emplace(0, 1);
            int sum = 0;

            while (!q.empty()) {
                auto [d, u] = q.top();
                q.pop();

                if (st[u]) continue;
                st[u] = true;
                sum = (sum + d) % mod;

                for (auto [v, w] : adj[u]) {
                    if (!st[v] && dist[v] > w) {
                        dist[v] = w;
                        q.emplace(dist[v], v);
                    }
                }
            }
            return sum;
        };

        cout << prim() << '\n';
    }
    return 0;
}