#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define MID ((l+r)>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define ls lc,l,MID
#define rs rc,MID+1,r
#define st 1,1,n
using namespace std;
LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b >> 1,M) : 1; }
LL gcd(LL a, LL b) { return b ? gcd(b, a%b) : a; }
const int N=1e5+1;
const int M=1e9+7;
int n;
LL a[62];
vector<LL>find(int i,LL sz){
	vector<LL>ans;
	LL n=1LL<<i;
	sz=min(sz,n);
	if(!sz)return ans;
	ans.PB(0);
	if(sz==1)return ans;
	ans.PB(n/2);
	if(sz==2)return ans;
	LL h=n/4,d=n/2;
	while((LL)ans.size()<sz){
		ans.PB(h);
		h+=d;
		if(h>=n){
			h=d/4;
			d/=2;
		}
	}
	return ans;
}
int main(){Accel
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	for(int i=n;i>=1;i--){
		vector<LL>v=find(i,a[i]+a[i+1]);
		for(int j=a[i+1];j<(int)v.size();j++)
			cout<<v[j]+(1LL<<i)<<endl;
		a[i]+=a[i+1];
	}
}
