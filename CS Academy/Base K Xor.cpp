
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
long long Ans,Pow,X,Y,T,A,B,K,p1,p2,a,b;
int main()
{
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d%d",&A,&B,&K);
		Ans=B*(B+1)/2-A*(A-1)/2;//處理個位數
		Ans%=K;
		//cout<<Ans<<endl;
		Pow=K;
		a=A/K;
		b=B/K;
		//從第一位數開始處理 每個位數為k^(i)的倍數
		while(b)
		{
			X=a%K,Y=b%K;
			p1=Pow*(1+A/Pow);//a 找最近的pow 的倍數x x<=a
			p2=Pow*(B/Pow);//b 找最近的pow倍數 y y>=a
			
			int aux=X*(p1-A)+Y*(B-p2+1);
			Ans+=aux%K*Pow;
			b/=K,a/=K;Pow*=K;
		}
		printf("%d\n",Ans);
	}
}
