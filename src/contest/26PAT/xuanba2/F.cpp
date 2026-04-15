#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    
    if (n % 2 == 0) return cout << n / 2, 0;

    int p = -1;
    for (int i = 3; i <= n / i; i += 2) {
        if (n % i == 0) {
            p = i; n -= i;
            break;
        }
    }

    if (p != -1) return cout << (1 + n / 2), 0;
    cout << 1;
    return 0;
}