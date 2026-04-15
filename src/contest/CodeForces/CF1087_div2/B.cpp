#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++ i) cin >> a[i];

        for (int i = 1; i <= n; ++ i) {
            int c1 = 0, c2 = 0;
            for (int j = i + 1; j <= n; ++ j) c1 += a[j] > a[i], c2 += a[j] < a[i];

            cout << max(c1, c2) << ' ';
        }
        cout << '\n';
    }
    return 0;
}