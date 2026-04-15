#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> p;

    auto eular = [&](int x) -> void {
        vector<bool> st(x + 1);
        for (int i = 2; i <= x; ++ i) {
            if (!st[i]) p.push_back(i);
            for (int j = 0; p[j] <= x / i; ++ j) {
                st[i * p[j]] = true;
                if (i % p[j] == 0) break;
            }
        }
    };

    eular(1e6);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n; cout << "1 2 ";
        for (int i = 0; i + 2 < n; ++ i) cout << p[i] * p[i + 1] << " ";
        cout << '\n';
    }
    return 0;
}