#include <bits/stdc++.h>
using namespace std;

using psi = pair<string, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, g, k; cin >> n >> g >> k;

    vector<psi> a(n + 1); int sum = 0;
    for (int i = 0; i < n; ++ i) {
        string s; int  sc; cin >> s >> sc;
        if (sc >= g) sum += 50;
        else if (sc >= 60) sum += 20;
        a[i + 1] = {s, sc};
    }


    sort(a.begin() + 1, a.end(), [&](psi x, psi y) -> bool {
        return x.second > y.second || x.second == y.second && x.first < y.first;
    });

    cout << sum << '\n';

    int p = 0;
    while (a[p].second >= a[k].second) p ++ ;

    for (int i = 1, pr = -1; i < p; ++ i) {
        auto t = a[i].second == a[i - 1].second ? pr : i;
        cout << t << " " << a[i].first << " " << a[i].second << '\n';
        pr = t;
    }
    return 0;
}