#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> a(30), b(30); a[1] = 2; b[1] = 1;

    int res = 0;
    for (int i = 2; i <= n; ++ i) a[i] = a[i - 1] + 2 * b[i - 1], b[i] = a[i - 1] + b[i - 1];

    cout << a[n] + b[n] << endl; 
    return 0;
}