#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int, double, greater<int>> ma, mb, ms; 
    int n; cin >> n;
    for (int i = 0; i < n; ++ i) {
        int p; cin >> p; cin >> ma[p];
    }
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        int p; cin >> p; cin >> mb[p];
    }

    auto [p, v] = *mb.begin();
    while (ma.size() && ma.begin() -> first >= p) {
        double d = ma.begin() -> second / v; int pd = ma.begin() -> first - p; ms[pd] = d;
        for (auto [a, b] : mb) {
            ma[a + pd] -= d * b;
            if (!ma[a + pd]) ma.erase(a + pd);
        }
    }

    cout << fixed << setprecision(1);

    if (!ms.size()) cout << "0 0 0.0\n";
    else {
        cout << ms.size() << " ";
        for (auto it = ms.begin(); it != ms.end(); ++ it) cout << it -> first << " " << it -> second << " \n"[it == prev(ms.end())];
    }

    if (!ma.size()) cout << "0 0 0.0\n";
    else {
        cout << ma.size() << " ";
        for (auto it = ma.begin(); it != ma.end(); ++ it) cout << it -> first << " " << it -> second << " \n"[it == prev(ma.end())];
    }
    return 0;
}