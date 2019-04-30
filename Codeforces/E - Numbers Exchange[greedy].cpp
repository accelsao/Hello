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
const int N=2e5+10;
const int M=1e9+7;
const double eps=1e-6;
const double PI(acos(-1.0));
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln()
//watch out LL
int n,m;
int d[N];
map<int,int>mp;
int cnt[2];
int main(){Accel
	int a=0,b=0,x;
	cin>>n>>m;	
	vector<int>id;
	FOR(i,1,n){
		cin>>d[i];
		if(mp[d[i]]||cnt[d[i]&1]==n/2)id.PB(i);
		else{
			mp[d[i]]=1;
			cnt[d[i]&1]++;
		}
	}
	int l=1,r=2,t=0;
	for(auto i:id){
		if(cnt[0]<n/2){
			while(mp[r])r+=2;
			if(r>m){
				cout<<-1<<endl;return 0;
			}
			d[i]=r;r+=2;
			cnt[0]++;
			t++;
		}
		else{
			while(mp[l])l+=2;
			if(l>m){
				cout<<-1<<endl;return 0;
			}
			d[i]=l;l+=2;
			cnt[1]++;
			t++;
		}
	}
	cout<<t<<endl;
	FOR(i,1,n)
		cout<<d[i]<<" ";
}
