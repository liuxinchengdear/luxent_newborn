#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        auto check = [&](double x) -> bool {
            double t = x;
            for (int i = 1; i < k; ++ i) {
                x *= t;
                if (x >= n) return true;
            }
            return false;
        };

        auto binary_search = [&](double l, double r) -> double {
            while (r - l > 1e-4) {
                double mid = (l + r) / 2;
                if (check(mid)) r = mid;
                else l = mid;
            }
            return r;
        };

        // cout << binary_search(1, n) << " " << check(3) << " ";

        cout << (int)binary_search(1, n) << '\n';
    }
    return 0;
}