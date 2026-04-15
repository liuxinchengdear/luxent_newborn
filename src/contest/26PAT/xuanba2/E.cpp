#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    int res = 0;
    vector<int> a{0, 2, 3, 4, 6, 7, 8, 9, 10};

    for (int i = 1; i <= 9; ++ i) res += i * (s[a[i - 1]] - 0x30);

    res %= 11;

    if (s.back() == res + 0x30 || s.back() == 'X' && res == 10) return cout << "Right\n", 0;
    

    s.back() = res + 0x30; if (res == 10) s.back() = 'X';

    cout << s << '\n';
    return 0;
}