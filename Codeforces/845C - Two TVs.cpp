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
const int N=2e5+1;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n;
vector<PII>v;
int main(){Accel
	cin>>n;
	int l,r;
	REP(i,n){
		cin>>l>>r;
		v.PB({l,1});
		v.PB({r+1,-1});
	}
	sort(ALL(v));
	int c=0;
	for(auto x:v){
		//cout<<x.F<<" "<<x.S<<endl;
		if(x.S>0)c++;
		else c--;
		if(c>2)return cout<<"NO\n",0;
	}
	cout<<"YES\n";
}
