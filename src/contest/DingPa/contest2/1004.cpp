#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        for (int i = 0; i < n - 2; ++ i) cout << "1 ";

        cout << "2 " << (k + n) << '\n';
    }
    return 0;
}