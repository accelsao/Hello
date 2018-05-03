#include <bits/stdc++.h>
#define ld long double
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
//typedef complex<double>C;
//const double PI(acos(-1.0));
//const double eps(1e-8);
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
const int N=1234567;
const int M=1e9+7;
int main(){Accel

}


// Hash
const LL M1=1e9+7;
const LL M2=1e9+9;
struct 	hsh{
	LL a,b;
	hsh(){
		a=b=0;
	}
	hsh(LL x){
		a=x%M1;
		b=x%M2;
	}
	hsh(LL A,LL B){
		a=A%M1;
		b=B%M2; 
	}
	hsh operator*(hsh x){
		return hsh(x.a*a,x.b*b);
	}
	hsh operator+(hsh x){
		return hsh(x.a+a,x.b+b);
	}
	LL get(){
		return a*M2+b;
	}
	
};
hsh pw[N],hs[N];

//Point2D
struct point{ 
    int x,y;  
    point(){}  
    point(int x_,int y_){x=x_;y=y_;}  
    bool operator < (const point& b)const  
    {  
        return x!=b.x?x<b.x:y<b.y;  
    }  
    point operator - (const point& b)const  
    {  
        return point(x-b.x,y-b.y);  
    }  
    LL operator * (const point& b)const  
    {  
        return (LL)x*b.y-(LL)y*b.x;  
    }  
}a[N];

//Complex number
struct Complex{
	ld real ,image;
	Complex(ld _real,ld _image){
		real=_real;
		image=_image;
	}
	Complex(){}
};
Complex operator+(const Complex &c1, const Complex &c2){  
    return Complex(c1.real + c2.real, c1.image + c2.image);  
}
Complex operator - (const Complex &c1, const Complex &c2){  
    return Complex(c1.real - c2.real, c1.image - c2.image);  
}  
Complex operator * (const Complex &c1, const Complex &c2)  {  
    return Complex(c1.real*c2.real - c1.image*c2.image, c1.real*c2.image + c1.image*c2.real);  
} 
