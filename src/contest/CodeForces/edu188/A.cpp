#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<bool> st(n + 1);
        string s; cin >> s; s = " " + s;

        vector<int> t(n + 1);
        for (int i = 1; i <= n; ++ i) t[i] = s[i] == 'L' ? -1 : 1;

        int i = 1, cnt = 0;
        while (!st[i] && i >= 1 && i <= n) st[i] = true, i += t[i], ++ cnt;

        cout << cnt << '\n';
    }
    return 0;
}