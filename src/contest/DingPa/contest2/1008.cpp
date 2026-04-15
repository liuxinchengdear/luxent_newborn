#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++ i) cin >> a[i];

        int mn = 0, p = -1;
        for (int i = 0, sum = 0; i < n; ++ i) {
            sum += a[i];
            if (sum < mn) mn = sum, p = i;
        }

        cout << p + 2 << '\n';
    }
    return 0;
}