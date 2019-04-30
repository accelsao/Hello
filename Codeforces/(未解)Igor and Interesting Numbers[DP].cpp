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
int t;
LL C[15][15],k;
int sz[16];
int f[20];
const string s="0123456789abcdef";
void calc(){
	Re(f,0);
	f[0]=1;
	REP(i,16){//max digit
		for(int j=8;~j;j--){//max len
			int x=f[j];
			for(int k=1;k<=j&&k<=sz[i];k++){
				x+=f[j-k]*C[j][k];
			}
			f[j]=x;
			//if(i==1)
			//	cout<<f[j]<<" ";
			
		}
		//if(i==1)cout<<endl;
		//cout<<i<<" "<<f[1]<<endl;
	}
}
int main(){
	
	
	FOR(i,0,10){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	
	cin>>k>>t;
	REP(i,16)sz[i]=t;
	sz[1]--;
//	FOR(i,0,15)cout<<sz[i]<<" ";cout<<endl;
	calc();
	sz[1]++;
	FOR(i,0,8)cout<<f[i]<<endl;
	
	int len;
	FOR(i,0,8){
		if((LL)f[i]*15<k){
			k-=f[i]*15;
		}
		else{
			int x=(k-1)/f[i]+1;
			cout<<s[x];
			sz[x]--;
			len=i;
			k-=(k-1)/f[i]*f[i];
			//k-=(x-1)*f[i];
			break;
		}
	}
	while(len--){
		REP(i,16){
			sz[i]--;calc();
			if(f[len]<k)sz[i]++,k-=f[len];
			else{
				cout<<s[i];
				break;
			}
		}
	}
}
