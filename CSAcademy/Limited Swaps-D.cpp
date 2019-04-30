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
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
const int N=1e5+1;
const int M=1e9+7;
const double eps=1e-6;
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n;
LL k;
int a[N],ans[N];
int st[N*4],cnt[N*4];
void build(int rt,int l,int r){
    if(l==r){
		st[rt]=a[l];
		cnt[rt]=1;
		return ;
	}
	int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    st[rt]=max(st[rt<<1],st[rt<<1|1]);
    cnt[rt]=cnt[rt<<1]+cnt[rt<<1|1];
}
int mx(int rt,int l,int r,int k){
	if(cnt[rt]<=k)return st[rt];
	int m=l+r>>1;
	if(cnt[rt<<1]<k)
		return max(st[rt<<1],mx(rt<<1|1,m+1,r,k-cnt[rt<<1]));
	return mx(rt<<1,l,m,k);
}
int del(int rt,int l,int r,int v){
	if(l==r){
		st[rt]=-1,
		cnt[rt]=0;
		return 0;
	}
	int ans=0,m=l+r>>1;
	if(st[rt<<1]>=v)
		ans=del(rt<<1,l,m,v);
	else 
		ans=cnt[rt<<1]+del(rt<<1|1,m+1,r,v);
	cnt[rt]=cnt[rt<<1]+cnt[rt<<1|1];
	st[rt]=max(st[rt<<1],st[rt<<1|1]);
	return ans;
}
int main(){Accel
    cin>>n>>k;
    FOR(i,1,n)cin>>a[i];
    build(1,1,n);
    FOR(i,1,n){
		int val=mx(1,1,n,k+1);//max num in 1~k+1
		int pos=del(1,1,n,val);//count number before val smaller than val
		ans[i]=val;
		k-=pos;
	}
	FOR(i,1,n)cout<<ans[i]<<" ";
	
}
