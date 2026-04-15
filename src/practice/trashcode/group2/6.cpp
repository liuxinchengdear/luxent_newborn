#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++ i) {
        int x; cin >> x; a[x] = i;
    }
    for (int i = 1; i <= n; ++ i) {
        int x; cin >> x; b[x] = i;
    }

    auto lcs = [&]() -> int {
        vector<int> t;
        for (int i = 1; i <= n; ++ i) {
            
        }
    };
}