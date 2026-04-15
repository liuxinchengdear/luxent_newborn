#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x) & - (x))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1); 
        for (int i = 1; i <= n; ++ i) cin >> a[i];

        int mx = 0;
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) mx = max(mx, a[i] ^ a[j]);
        }
        cout << mx << '\n';
    }
    return 0;
}