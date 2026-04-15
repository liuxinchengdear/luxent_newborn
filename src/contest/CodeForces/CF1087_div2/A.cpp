#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, c, k; cin >> n >> c >> k;

        map<int, int> mp;
        for (int i = 0; i < n; ++ i) {
            int x; cin >> x; mp[x] ++ ;
        }

        while (mp.size() && mp.begin() -> first <= c) {
            auto p = prev(mp.lower_bound(c + 1));
            auto t = c;
            c += min(c, p -> first + k); k -= min(k, t - p -> first);
            p -> second -- ; 
            if (p -> second == 0) mp.erase(p);
        }

        cout << c << '\n';
    }
    return 0;
}