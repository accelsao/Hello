#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define F first
#define S second
using ll = long long;
const int N = 1e6 +10;
const int M = 1e6 + 3;
const int inf = 1e9+7;
const ll INF = 1e18;

ll a[15][15];
int b[15];
ll pw(ll a, ll b){
	ll t=1;
	while(b){
		if(b&1){
			t=t*a%M;
		}
		a=a*a%M;
		b>>=1;
	}
	return t;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	printf("? 0\n");
	fflush(stdout);

	cin>>b[0];
	
	for(int i=1;i<=10;i++){
		printf("? %d\n", i);
		fflush(stdout);
		a[i][0]=1;
		for(int j=1;j<=10;j++){
			a[i][j]=a[i][j-1]*i%M;
		}
		cin>>a[i][11];
		a[i][11]-=b[0];
		a[i][11]+=M;
		a[i][11]%=M;
	}
	
	//10x11
	for(int i=1;i<=10;i++){
		
		int row=i;
		for(int j=i+1;j<=10;j++){
			if(a[j][i]>a[row][i]){
				row=j;
			}
		}
		for(int j=i;j<=11;j++){
			swap(a[row][j], a[i][j]);
		}
//		printf("Before:\n");
//		for(int i=1;i<=10;i++){
//			for(int j=1;j<=11;j++){
//				printf("%d ", a[i][j]);
//				
//			}
//			printf("\n");
//		}
		
		if(!a[i][i])continue;
		
		ll div=pw(a[i][i], M-2);
		for(int j=i;j<=11;j++){
			a[i][j]=a[i][j]*div%M;
		}
		
//		printf("After Normalize:\n");
//		for(int i=1;i<=10;i++){
//			for(int j=1;j<=11;j++){
//				printf("%d ", a[i][j]);
//				
//			}
//			printf("\n");
//		}
		
		for(int j=i+1;j<=10;j++){
			ll p=a[j][i];
			if(p){
				for(int k=i;k<=11;k++){
					a[j][k]=(a[j][k]-a[i][k]*p%M+M)%M;
				}
			}
		}
		
//		printf("After:\n");
//		for(int i=1;i<=10;i++){
//			for(int j=1;j<=11;j++){
//				printf("%d ", a[i][j]);
//				
//			}
//			printf("\n");
//		}
	}
	
	for(int j=10;j>=1;j--){
		for(int i=j-1;i>=1;i--){
			a[i][11]-=a[i][j]*a[j][11]%M;
			a[i][11]+=M;
			a[i][11]%=M;
		}
		b[j]=a[j][11];
	}
//	for(int j=0;j<=10;j++)
//		printf("%d ", b[j]);puts("");
//	
	for(int i=0;i<M;i++){
		ll sum=0;
		ll p=1;
		for(int j=0;j<=10;j++){
			sum+=b[j]*p;
			sum%=M;
			p=p*i%M;
		}
//		printf("%d: %lld\n",i, sum);
		if(!sum){
			printf("! %d\n",i);
			fflush(stdout);
			return 0;
		}
	}
	printf("! -1\n");
	fflush(stdout);
}

/*
1000002
0
3
8
15
24
35
48
63
80
99

*/

