#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<int> st{3, 4, 5, 3, 23, 32, 55};

    auto p = st.begin(), np = st.begin(); np = next(np);

    advance(p, 3); cout << distance(np, p) << endl;

    // 减数 被减数

    cout << *p << " " << *np << endl;
    return 0;
}