#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++ i) cin >> a[i];

        int p; cin >> p;

        int mx = 0;
        for (int i = 1, t = 0; i <= p; ++ i) (a[i] + t) % 2 == a[p] ? 0 : mx = max(mx, ++ t);
        for (int i = n, t = 0; i >= p; -- i) (a[i] + t) % 2 == a[p] ? 0 : mx = max(mx, ++ t);

        cout << mx << '\n';
    }
    return 0;
}