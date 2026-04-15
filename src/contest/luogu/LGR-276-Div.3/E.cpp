#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;

    // 算出最多能经过的矿洞数

    vector<int> c(n + 2), a(n + 1);
    for (int i = 2; i <= n; ++ i) cin >> c[i];
    for (int i = 1; i <= n; ++ i) cin >> a[i];

    vector<int> nc(n + 2);
    for (int i = 1; i <= n; ++ i) nc[i] = nc[i - 1] + c[i];

    int p = lower_bound(nc.begin(), nc.end(), m + 1) - nc.begin(); p = min(n, p - 1);

    vector<int> na(p + 1); multiset<int, greater<int>> st;
    for (int i = 1; i <= p; ++ i) {
        st.insert(a[i]); 
        int sum = 0, cnt = 0;
        for (auto e : st) {
            sum += e;
            if ( ++ cnt >= k) break;
        }
        na[i] = sum;
    }

    int mx = 0;
    for (int i = 1; i <= p; ++ i) mx = max(mx, min(m - nc[i], na[i]));

    cout << mx << '\n';
    return 0;
}