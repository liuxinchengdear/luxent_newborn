#include <bits/stdc++.h>
using namespace std;

signed main() {
    double x = 0.05, y = 0.04;

    map<int, int> mp;

    mp[1] = 1; mp[2] = 2; mp[3] = 3;

    for (auto it = mp.begin(); it != mp.end(); ) {
        if (it -> first == 2) mp.erase(it ++ );
        else ++ it;
    }

    return 0;
}