#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<int, greater<int>> st; st.insert(3);

    for (auto e : st) cout << e << endl;
    return 0;
}