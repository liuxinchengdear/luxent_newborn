#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int a, b, c, m; cin >> a >> b >> c >> m;

        int mab = a * b / gcd(a, b), mac = a * c / gcd(a, c), mbc = b * c / gcd(b, c);
        int mabc = mab * c / gcd(mab, c);

        auto cal = [&](int x, int m1, int m2) -> int {
            int c3 = m / mabc, c2 = m / m1 + m / m2 - 2 * c3, c1 = m / x - c2 - c3;
            return 6 * c1 + 3 * c2 + 2 * c3;
        };

        cout << cal(a, mab, mac) << " " << cal(b, mab, mbc) << " " << cal(c, mac, mbc) << '\n';
    }
    return 0;
}