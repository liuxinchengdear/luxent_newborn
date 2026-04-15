#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        int sum = 0;
        for (int i = 0; i < n; ++ i) {
            int x; cin >> x; sum += x;
        }

        cout << (sum & 1 || (k * n) % 2 == 0 ? "yes\n" : "no\n");
    }
    return 0;
}