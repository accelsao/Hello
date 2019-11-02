#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define F first
#define S second
using ll = long long;
const int N = 1e5 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;


int nxt[N][30];
int dp[256][256][256];
vector<int> a[10];
int n, q;
void compute(int i, int j, int k){
	int& val = dp[i][j][k];
	val=n;

	if(i)val=min(val, nxt[dp[i-1][j][k]+1][a[1][i-1]]);

	if(j)val=min(val, nxt[dp[i][j-1][k]+1][a[2][j-1]]);

	if(k)val=min(val, nxt[dp[i][j][k-1]+1][a[3][k-1]]);

}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n>>q;
	string s;
	cin>>s;
	
	for(int i=n;i<N;i++)
		for(int j=0;j<30;j++)
			nxt[i][j]=n;
	
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<30;j++){
			nxt[i][j]=nxt[i+1][j];
		}
		nxt[i][s[i]-'a']=i;
	}
//	for(int i=0;i<256;i++)
//		for(int j=0;j<256;j++)
//			for(int k=0;k<256;k++)	
//				dp[i][j][k]=n;

	dp[0][0][0]=-1;

	char op, ch;
	int clr;
	while(q--){
		cin>>op;
		if(op=='+'){
			cin>>clr>>ch;
			a[clr].push_back(ch-'a');
			
			for(int i=(clr==1)*a[1].size();i<=a[1].size();i++)
				for(int j=(clr==2)*a[2].size();j<=a[2].size();j++)
					for(int k=(clr==3)*a[3].size();k<=a[3].size();k++){
						compute(i,j,k);
					}
		}
		else{
			cin>>clr;
			a[clr].pop_back();
		}
		
//		printf("%d\n",dp[a[1].size()][a[2].size()][a[3].size()]);
		
		puts(dp[a[1].size()][a[2].size()][a[3].size()]<n?"YES":"NO");
	}
}
/*
6 2
abdabc
+ 1 a
+ 1 a

*/

