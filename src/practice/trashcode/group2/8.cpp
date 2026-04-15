#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N],b[N],n,m;

bool check(ll mid){
	int ind=upper_bound(a+1,a+n+1,mid)-a;
	ll s=0;
	for (int i=1;i<ind;i++) s+=a[i]*b[i];
	s+=mid*b[ind];
	for (int i=ind;i<=n;i++) s+=a[i]*b[i+1];
	return s>=m;
}

void solve(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n+1;i++) cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+2);
	
	ll sum=0;
	for (int i=1;i<=n;i++) {
        sum+=a[i]*b[i+1];
        if (sum >= m) {
            cout << "0\n";
            return;
        }
    }
	
	ll L=1,R=1e9;
	while (L!=R-1){
		ll mid=(L+R)/2;
		if (check(mid)) R=mid;
		else L=mid;
	}
	cout<<R<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--) solve();
	return 0;
}