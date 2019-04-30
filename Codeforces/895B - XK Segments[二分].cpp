#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
#define LL long long 
vector<LL>v;
 LL n,x,k;
int main(){
	cin>>n>>x>>k;
	v.resize(n);
	for(auto &it:v)cin>>it;
	sort(v.begin(),v.end());
	LL ans=0;
	for(auto i:v){
		LL l=i/x*x+(k-(i%x==0))*x,r;
		r=l+x;l=max(l,i);
		//cout<<l<<' '<<r<<endl;
		LL d=lower_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
		//cout<<d<<endl;
		ans+=d;
	}
	cout<<ans<<endl;
	
}
