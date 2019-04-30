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
#define SZ(a) ((int)a.size())
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
int n,k,w;
int a[N],b[N];
int l=1,r=1,t,ans,tmp;
multiset<int>s,g;
int main(){Accel
	cin>>n>>w>>k;
	FOR(i,1,n){
		cin>>a[i];
	}
	FOR(i,1,n){
		cin>>b[i];
	}
	while(r<=n){
		t+=(b[r]+1)/2;
		tmp+=a[r];
		s.insert(b[r++]);
		if(SZ(s)>w){
			auto it=s.begin();
			g.insert(*it);
			t+=(*it)/2;
			s.erase(it);
		}
		while(l<=r&&t>k){
			if(b[l]>=*s.begin()){//b[l] in w
				t-=(b[l]+1)/2;
				s.erase(s.find(b[l]));
				if(SZ(g)){
					auto j=g.end();j--;
					s.insert(*j);
					t-=*j/2;
					g.erase(j);
				}
			}
			else{
				t-=b[l];
				g.erase(g.find(b[l]));
				
			}
			tmp-=a[l++];
		}
		ans=max(ans,tmp);
	}
	
	cout<<ans<<endl;
	
}
