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
const int N=7e4+10;
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
int t;
struct A{
	int l,r,w;
};
int id[N];

int f[4][N];
int n,k;
map<int,int>mp;
int get(int x){
	return mp[x]?mp[x]:mp[x]=SZ(mp);
}
int find(int i,int x){
	if(i==0)return 0;
	int mx=-1;
	while(x){
		mx=max(mx,f[i][x]);
		x-=x&-x;
	}
	return mx;	
}
void add(int i,int x,int v){
	while(x<=k){
		cout<<x<<" "<<v<<endl;
		f[i][x]=max(v,f[i][x]);
		x+=x&-x;
	}
}
bool cmp(A a,A b){
	return a.l<b.l||(a.l==b.l&&a.r<b.r);
}
int L[N];
int main(){Accel
	cin>>t;
	while(t--){
		Re(f,-1);
		mp.clear();
		cin>>n;
		vector<A>v(n);
		set<int>p;
		REP(i,n){
			cin>>v[i].l>>v[i].r>>v[i].w;
			p.insert(v[i].l);
			p.insert(v[i].r);
		}
		
		k=0;
		for(auto x:p)
			id[++k]=x,mp[x]=k;
		REP(i,n){
			
			v[i].l=mp[v[i].l];v[i].r=mp[v[i].r];
		}
		sort(ALL(v),cmp);
		int i=0,j=0,tmp=0;
		priority_queue<PII>del;
		while(i<n){
			int l=v[i].l,r=v[i].r,w=v[i].w;
			while(SZ(del)&&-del.top().F<l){
				tmp-=del.top().S;
				
				del.pop();
			}
			while(i<n&&v[i].l==l){
				del.push(MP(-v[i].r,v[i].w));
				tmp+=v[i].w;
				i++;
			}
			
			//cout<<tmp<<" "<<-del.top().F<<endl;
			for(int k=3;k;k--){
				int val=find(k-1,v[j].l-1);
				cout<<val<<endl;
				if(~val)
					add(k,l,val+tmp);
			}
			
		}
		int ans=find(3,id[k]);
		cout<<ans<<endl;
	}
}
