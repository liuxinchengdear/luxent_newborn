#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        int res = 0; vector<bool> st(n + 1); 
        for (int i = 0; i < n; ++ i) {
            int x; cin >> x; 
            res += x <= n && !st[x]; if (x <= n) st[x] = true;
        }
        cout << res << '\n';
    }
    return 0;
}