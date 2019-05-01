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
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
const int N=1e5+1;
const int M=1e9+7;
set<LL>s,t;
int n;
int main(){Accel
    cin>>n;
    LL ans=0;
    vector<LL>v(n);
    for(auto &it:v)cin>>it;
    sort(ALL(v));
    queue<LL>q;
    while(q.size()||v.size()){
		LL mx=0;
		if(q.size())mx=q.front();
		if(v.size())mx=max(mx,v.back());
		ans++;
		if(mx/2)q.push(mx/2);
		while(q.size()&&q.front()==mx)q.pop();
		while(v.size()&&v.back()==mx)v.pop_back();
	}
	cout<<ans-1<<endl;
}
