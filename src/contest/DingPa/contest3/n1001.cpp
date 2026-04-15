#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, N = 5010;

int a[N + 1][N + 1];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= N; ++ i) a[i][1] = a[i][i] = 1;
    for (int i = 1; i <= N; ++ i) {
        for (int j = 2; j < i; ++ j) a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % mod;
    }

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++ i) cin >> a[i];

        sort(a.begin() + 1, a.end());
        int sum = 0;
        for (int i = 2; i <= n; ++ i) sum = (sum + (a[1] <= a[i] - a[i - 1] ? ::a[a[i] + 1][a[1] + 1] : ::a[a[i] + 1][a[i - 1] + 1])) % mod;
        
        cout << sum << '\n';
    }
    return 0;
}