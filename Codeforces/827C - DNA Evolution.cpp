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
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
string s;
int n;
map<char,int>mp;
int BIT[11][11][4][N];//len pos char s[len] 
//len 長度下有 len個起始點 (pos%len)
int a[N][4];
void add(int len,int pos,int chr,int x,int val){
	while(x<=n){
		BIT[len][pos][chr][x]+=val;
		x+=x&-x;
	}
}
int find(int len,int pos,int chr,int x){
	int s=0;
	while(x){
		s+=BIT[len][pos][chr][x];
		x-=x&-x;
	}
	return s;
}
int main(){Accel
	mp['A']=0;mp['C']=1;mp['T']=2;mp['G']=3;
	int q;
	cin>>s>>q;
	n=s.size();
	FOR(l,1,10)FOR(i,1,n)add(l,i%l,mp[s[i-1]],i,1);
	//e最多10 store 10個起始點 
	while(q--){
		int t,l,r;
		string tmp;
		cin>>t;
		if(t==1){
			char c;
			cin>>l>>c;
			FOR(i,1,10){
				add(i,l%i,mp[s[l-1]],l,-1);
				add(i,l%i,mp[c],l,1);
			}
			s[l-1]=c;
		}
		else{
			cin>>l>>r>>tmp;
			int len=tmp.size();
			int ans=0;
			//seg[l,r]=find(r)-find(l-1)
			FOR(i,1,len)ans+=find(len,(l+i-1)%len,mp[tmp[i-1]],r)-find(len,(l+i-1)%len,mp[tmp[i-1]],l-1);
			//len長度下 (l+i-1)%len起點
			cout<<ans<<endl;
		}
		
	}
}
