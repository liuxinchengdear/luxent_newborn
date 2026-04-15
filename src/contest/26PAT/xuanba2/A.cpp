#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int mx = -1e9, mn = 1e9, cnt = 0;
    int p, q;

    for (int i = 1; i <= n; ++ i) {
        int a, b; cin >> a >> b;

        if (a - b >= mx) mx = a - b, p = i;
        if (a - b <= mn) mn = a - b, q = i;

        cnt += a == b;
    }

    cout << p << " " << q << " " << cnt << '\n';

    return 0;
}