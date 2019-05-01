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
#define PLL pair<LL,LL>
using namespace std;
const int N=1e5+1;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int main(){Accel
	string s;
	cin>>s;
	int n=s.size();
	vector<int>pos[26];
	REP(i,n)pos[s[i]-'a'].PB(i);
	int mx=0;
	REP(i,26)mx=max(mx,(int)pos[i].size());
	string ans="";
	REP(i,26){
		int sz=1;
		if(pos[i].size()!=mx)continue;
		while(pos[i].back()+sz<n){
			char ch=s[pos[i][0]+sz];
			bool f=1;
			for(auto it:pos[i])
				f&=s[it+sz]==ch;
			if(!f)break;
			sz++;
		}
		string str="";
		REP(j,sz)
			str+=s[pos[i][0]+j];
		if(sz>ans.size()||ans>str)ans=str;
	}
	cout<<ans<<endl;
}
