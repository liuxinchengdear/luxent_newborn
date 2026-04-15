#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

int fp(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod; n >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // a1 = y = 2 ^ 0 * y
    // a2 = y + a1 = 2 ^ 1 * y
    // a3 = y + a1 + a2 = 2 ^ 2 * y

    // an = 2 ^ (n - 1) * y

    // Sn = a1 + a2 + ... + an = (2 ^ n - 1) * y
    // Tn = S1 + S2 + ... + Sn

    // Tn = (n + 1) * Sn - (1 * a1 + 2 * a2 + ... )

    // Tn' = 1 * a1 + 2 * a2 + ...
    // 2 * Tn' = 1 * a2 + ...

    // -Tn' = a1 + (a2 + ... + an) - n * a(n + 1)
    // Tn' = -Sn + n * 2 ^ n * y

    int _T; cin >> _T; while (_T -- ) {
        int x, y; cin >> x >> y; y += 1;

        if (x <= y) { cout << x << '\n'; continue; }

        int n = x - y, s = (fp(2, n) - 1) * y % mod;

        int T = (-s + n * fp(2, n) % mod * y % mod + mod) % mod;

        cout << (s + y) % mod << '\n';
    }
    return 0;
}