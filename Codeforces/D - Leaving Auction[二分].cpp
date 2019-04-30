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
//#pragma GCC optimize(2)
using namespace std;
const double eps=1e-3;
//typedef complex<double>C;
//const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
const int N=2e5+1;

int n;
int a[N],b[N];
vector<int>v[N];
int f[N];
int id[N];
set<PII>s;
int get(){
	if(SZ(s)==0)return 0;
	auto it=s.rbegin();
	if((*it).F==0)return 0;
	return (*it).S;
}
int main(){Accel
	cin>>n;
	FOR(i,1,n){
		cin>>a[i]>>b[i];
		v[a[i]].PB(i);
		f[a[i]]=i;
	}
	FOR(i,1,n){
		s.insert(MP(f[i],i));
	}
	
	
	int q;
	cin>>q;
	FOR(i,1,q){
		int t;
		cin>>t;
		FOR(j,1,t){
			cin>>id[j];
			s.erase(MP(f[id[j]],id[j]));
		}
		int k,p;
		if(SZ(s)==0){cout<<"0 0\n";}
		else {
			auto it=s.rbegin();
			if((*it).F==0){
				cout<<"0 0\n";
			}
			else{
				k=(*it).S;
				s.erase(MP(f[k],k))	;
				if(SZ(s)==0){
					p=0;
				}
				else{
					p=(*s.rbegin()).F;
				}
				int g=lower_bound(ALL(v[k]),p)-v[k].begin();
				g=v[k][g];
				cout<<k<<" "<<b[g]<<endl;
				s.insert(MP(f[k],k));
			}
		}

		FOR(j,1,t){
			s.insert(MP(f[id[j]],id[j]));
		}
		
	}
}
