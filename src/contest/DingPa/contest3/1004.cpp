#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        vector<int> a(n + 1);

        for (int i = 1; i <= n; ++ i) {
            for (int j = i << 1; j <= n; j += i) ++ a[i], ++ a[j];
        }

        // for (int i = 1; i <= n; ++ i) cout << a[i] << " "; cout << endl;

        sort(a.begin() + 1, a.end(), greater<int>());
        cout << a[k] << '\n';
    }
    return 0;
}