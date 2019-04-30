//注意double精度  先*1.0保證精度
 /*
 任意l,r 1<=l<=r<=n 
 ans= inv(1,n)-inv(1,r)+exp(k)
 ans/=n*(n+1)/2
 k=r-l+1;
exp[n]=n*(n-1)/4
n!的排列 對於任意一個都有reverse 他們的逆序數和 = n*(n-1)/2
exp[n]=n!/2* (n*(n-1)/2)  /n!
=n*(n-1)/4
*/

#include <bits/stdc++.h>
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define LL long long
using namespace std;
const int N=2e5+1;
int n;
LL BIT[2][N];
int a[N];
int main(){Accel
	cin>>n;
	int x;
	double ans=0;
	FOR(i,1,n)cin>>a[i];
	for(int i=n;i;i--){
		int j=a[i];
		while(j){
			ans+=BIT[0][j];
			ans-=2.*i*BIT[1][j]/n/(n+1);
			j-=j&-j;
		}
		j=a[i];
		while(j<=n){
			BIT[0][j]++;
			BIT[1][j]+=n+1-i;
			j+=j&-j;
		}
		ans+=(n-i+1.)*i*(i-1)/n/(n+1)/2;
	}
	cout<<fixed<<setprecision(13)<<ans<<endl;
}
