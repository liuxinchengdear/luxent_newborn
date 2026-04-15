#include <bits/stdc++.h>
using namespace std;

//产品部门G或者销售部门H中

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    string s; cin >> s; s = " " + s;

    vector<int> a(n + 1), g, h;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) {
        s[i] == 'G' ? g.push_back(i) : h.push_back(i);
    }

    vector<int> pg(n + 1), ph(n + 1);
    for (int i = 1; i <= n; ++ i) {
        pg[i] = pg[i - 1] + (s[i] == 'G');
        ph[i] = ph[i - 1] + (s[i] == 'H');
    }

    int res = 0;
    if (a[g.front()] >= g.back()) {
        res = 1;
        for (int i = 1; i < g.front(); ++ i) res += s[i] == 'H' && a[i] >= g.front();
    }
    if (a[h.front()] >= h.back()) {
        res += 1;
        for (int i = 1; i < h.front(); ++ i) res += s[i] == 'G' && a[i] >= h.front();
    }

    cout << res << '\n';
    return 0;
}