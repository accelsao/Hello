# Problem statement
Gerrymandering is a practice intended to establish a political advantage for a particular party or group by manipulating district boundaries.  

An election between the political parties A and B has taken place in N counties. Therefore, each county has chosen to represent either A or B.  

* Each county belongs to one district  
* If i,j are same [i+1,j-1] are same as i and j  
* Each district must contain one and only one large county  

A is majority in a district if the number of counties (belonging to this district) voting for it is greater or equal to the number of counties voting for the opposite party.  

Find a split which maximizes the number of districts in which A is majority. Print its number of districts.  
# Constraints and notes
* <a href="https://www.codecogs.com/eqnedit.php?latex=1\leq&space;N\leq&space;10^{5}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?1\leq&space;N\leq&space;10^{5}" title="1\leq N\leq 10^{5}" /></a>  
* There is at least one large country
# Input Note
* A,B  Type
* S-small,L-Large  
# Solution
maintain f[i][0] the i district with the min (A-B),f[i][1] with the max(A-B)
if the min <= max,imply that we can have one A major district  (A>=B)  
otherwise tmp=min ,take as many B as you can for the "NG" district  
```cpp
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
const int N=1e6+1;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int t=0;while(x){t+=BIT[x];x-=x&-x;}return t;}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
int n;
int f[N][2];
int main(){//Accel
    cin>>n;
    int c=0,s=0;
    REP(i,n){
		char a,b;
		cin>>a>>b;
		if(a=='A')c++;else c--;
		if(b=='L'){
			s++;
			f[s][0]=f[s][1]=c;
		}
		if(s>=1){
			f[s][0]=min(f[s][0],c);
			f[s][1]=min(f[s][1],c);
		}
		
	}
	f[s][0]=f[s][1]=c;
	int ans=0,tmp=0;
	for(int i=1;i<=s;i++){
		tmp=max(tmp,f[i][0]);
		if(tmp<=f[i][1])
			ans++;
		else tmp=f[i][0];
	}
	cout<<ans<<endl;
}
```
