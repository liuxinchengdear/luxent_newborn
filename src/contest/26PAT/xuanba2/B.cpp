#include <bits/stdc++.h>
using namespace std;

#define double long double

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    auto check = [&](double x) -> bool {
        for (int i = 0; i < n; ++ i) {
            x *= 1.0372; 
            x -= 1000;
            if (x < 0) return false;
        }
        return true;
    };

    auto binary_search = [&](double l, double r) -> double {
        while (abs(l - r) > 1e-4) {
            double mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid;
        }
        return r;
    };

    cout << fixed << setprecision(2);

    cout << binary_search(500, n * 1000) << '\n';
    return 0;
}