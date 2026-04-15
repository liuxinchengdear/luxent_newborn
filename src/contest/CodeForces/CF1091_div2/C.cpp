#include <bits/stdc++.h>
using namespace std;

int exg(int a, int b, int &x, int &y) {
    if (!b) { x = 1; y = 0; return a; }
    int d = exg(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, a, b; cin >> n >> m >> a >> b;

        int x1, x2, y1, y2;
        // a * x1 + n * y1 = c1
        // b * x2 + m * y2 = c2

        if (exg(a, n, x1, y1) != 1 || exg(b, m, x2, y2) != 1) { cout << "no\n"; continue; }

        // 可得到 x1 和 x2 的特解
        // x1 = x1' + n / d1 * t   x2 = x2' + m / d2 * t  d1 = d2 = 1

        // abs(x1' + n * t1 - x2' - m * t2) <= 1

        x1 = (x1 % n + n) % n; x2 = (x2 % m + m) % m;

        // x1 * x + n * y = x2
        cout << (x2 % gcd(x1, n) == 0 ? "yes\n" : "no\n");
    }
    return 0;
}