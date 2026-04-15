#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        vector<int> a(7); for (auto &e : a) cin >> e;

        sort(a.begin(), a.end());

        int sum = 0;
        for (int i = 0; i < 6; ++ i) sum += -a[i];
        sum += a.back();
        cout << sum << endl;
    }
    return 0;
}