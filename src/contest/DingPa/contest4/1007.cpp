#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, s; cin >> n >> s;
        vector<int> a(n);
        for (auto &e : a) cin >> e;

        sort(a.begin(), a.end());

        auto p = lower_bound(a.begin(), a.end(), s);
        if (p == a.end() || *p != s) { cout << "NO\n"; continue; }

        int cs = count(a.begin(), a.end(), s), c0 = count(a.begin(), a.end(), 0);

        cout << (cs == n || cs + c0 == n ? "YES\n" : "NO\n");
    }
    return 0;
}