#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> a(25);
    a[0] = a[1] = 1;
    for (int i = 2; i < 25; ++ i) a[i] = a[i - 1] + a[i - 2];

    for (int i = 1; i <= n; ++ i) cout << a[i] << '/' << a[i + 1] << " ";
    return 0;
}