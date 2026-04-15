#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        vector<vector<int>> g(n + 1); map<int, int, greater<int>> mp;
        for (int i = 1; i <= n; ++ i) cin >> a[i], g[a[i]].push_back(i), mp[a[i]] ++ ;

        int p = n, cnt = 0;
        while (p) {
            ++ cnt;
            auto t = mp.begin() -> first;
            auto pos = g[t].back(); 
            while (p >= pos) {
                mp[a[p]] -- ; g[a[p]].pop_back();
                if (!mp[a[p]]) mp.erase(a[p]);
                p -- ;
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}