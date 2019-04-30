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
#define PII pair<int,int>
using namespace std;
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
const int N=1e5+1;
const int M=1e9+7;
string s;
int i,len,n,mn,T,ans;
vector<int>sz;
int main(){
	cin>>s;
	n=s.size();
	for(i=len=1;i<=n;i++,len++)
		if(i==n||(s[i]!=s[i-1])){
			if(i==n||i==len||len>2)s[T++]=s[i-1],sz.PB(len);
			len=0;
		}
	for(mn=1;(n=T)>1;){
		for(T=i=0;i<n;i++){
			if((sz[T]=sz[i]-(!i||i+1==n?mn:mn*2))>0)
				if(T&&s[i]==s[T-1])sz[T-1]+=sz[T];//merge
				else s[T++]=s[i];
		}
		//cout<<s<<endl;
		ans+=mn;
		//cout<<mn<<endl;
		mn=min(sz[0],sz[T-1]);
		for(i=1;i<T-1;i++)
			mn=min(mn,max(sz[i]/2,1));
	}
	cout<<ans<<endl;
}
