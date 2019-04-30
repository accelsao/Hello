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
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
const int N=1e5+1;
const int M=1e9+7;
typedef pair<int,LL> p2;
typedef pair<LL,p2> p3;
int n,p[N][2],h;
LL mx=1LL<<42,B,R;
vector<p3>a;
void dfs(int i,LL rs,int rn,LL bit){//紅比藍多的sum and num 
	if(i==h){
		a.PB(p3(rs,p2(rn,bit)));
		return ;
	}
	dfs(i+1,rs+p[i][0],rn-1,bit);
	dfs(i+1,rs-p[i][1],rn+1,bit|(1LL<<i));
}
void sdf(int i,LL rs,int rn,LL bit){
	if(!mx)return;
	if(i==n){
		auto it=lower_bound(ALL(a),p3(-rs,p2(-N,0)));
		while(it!=a.end()&&it->F==-rs){
		    //cout<<rn<<" "<<it->S.F<<endl;
			if(labs(rn+it->S.F)<mx){
				mx=labs(rn+it->S.F);
				B=it->S.S,R=bit;
			}
			else break;
		}
		return;
	}
	sdf(i+1,rs+p[i][0],rn-1,bit);
	sdf(i+1,rs-p[i][1],rn+1,bit|(1LL<<(i-h)));
}
int main(){Accel
    cin>>n;
    REP(i,n)cin>>p[i][0]>>p[i][1];
    h=n/2;
    dfs(0,0,0,0);
    sort(ALL(a));
    sdf(h,0,0,0);    
    if(mx==1LL<<42)puts("-1");
    else{
		REP(i,h)
			if((1<<i)&B)putchar('1');
			else putchar('0');
		REP(i,n-h)
			if((1<<i)&R)putchar('1');
			else putchar('0');
		cout<<endl;
	}
}
