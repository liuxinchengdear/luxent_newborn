#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, N = 5010;

int c[N + 1][N + 1], g[2010][2010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= N; ++ i) c[i][1] = c[i][i] = 1;
    for (int i = 1; i <= N; ++ i) for (int j = 2; j < i; ++ j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++ i) cin >> a[i];

        memset(g, 0x3f, sizeof g);

        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) g[i][j] = min(g[i][j], c[max(a[i], a[j]) + 1][min(a[i], a[j]) + 1]);
        }

        auto prim = [&]() -> int {
            vector<int> dist(n + 1, 1e9); dist[1] = 0;
            vector<bool> st(n + 1);

            int sum = 0;
            for (int i = 0; i < n; ++ i) {
                int t = -1;
                for (int j = 1; j <= n; ++ j) {
                    if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
                }

                if (dist[t] == 1e9) return 1e9;
                st[t] = true; sum = (sum + dist[t]) % mod;

                for (int j = 1; j <= n; ++ j) dist[j] = min(dist[j], g[t][j]);
            }
            return sum;
        };

        cout << prim() << '\n';
    }
    return 0;
}