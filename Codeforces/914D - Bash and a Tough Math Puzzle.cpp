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
const int N=5e5+1;
int n,a[N],st[N*4];
void build(int rt,int l,int r){
	if(l==r){
		st[rt]=a[l];
		return ;
	}
	int m=(l+r)>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
	st[rt]=__gcd(st[rt<<1],st[rt<<1|1]);
}
void fix(int rt,int l,int r,int pos,int x){
	if(l==r){
		st[rt]=x;
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)fix(rt<<1,l,m,pos,x);
	else fix(rt<<1|1,m+1,r,pos,x);
	st[rt]=__gcd(st[rt<<1],st[rt<<1|1]);
}
int find(int rt,int l,int r,int L,int R,int x){
	if(l>R||r<L)return 0;
	int m=(l+r)>>1;
	if(l>=L&&r<=R){
		if(st[rt]%x==0)return 0;
		if(l==r)return 1;
		if(st[rt<<1]%x==0)return find(rt<<1|1,m+1,r,L,R,x);
		if(st[rt<<1|1]%x==0)return find(rt<<1,l,m,L,R,x);
		return 2;
	}
	return find(rt<<1,l,m,L,R,x)+find(rt<<1|1,m+1,r,L,R,x);
}
int main(){Accel
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	build(1,1,n);
	int q,ty,l,r,x;
	cin>>q;
	while(q--){
		cin>>ty;
		if(ty==1){
			cin>>l>>r>>x;
			if(find(1,1,n,l,r,x)>1)puts("NO");
			else puts("YES");
		}
		else {
			int pos;
			cin>>pos>>x;
			fix(1,1,n,pos,x);
		}
	}
}
