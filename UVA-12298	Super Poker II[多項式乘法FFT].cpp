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
const int N=50010;
const int M=1e9+7;
const long double PI = acos(-1.0);  
  
bool isPrime[50010];  
bool check[50010];  
  
void init()  
{  
    memset(isPrime, 0, sizeof(isPrime));  
    memset(check, 0, sizeof(check));  
    isPrime[0] = isPrime[1] = 1;  
    check[0] = check[1] = 1;  
    for(int i = 2; i <= 50000; i++)  
    {  
        if(check[i]) continue;  
        isPrime[i] = 1;  
        for(int j = i; j <= 50000; j += i)  
            check[j] = 1;  
    }  
    return;  
}  
  
struct Complex  
{  
    long double real, image;  
    Complex(long double _real, long double _image)  
    {  
        real = _real;  
        image = _image;  
    }  
    Complex(){}  
};  
  
Complex operator + (const Complex &c1, const Complex &c2)  
{  
    return Complex(c1.real + c2.real, c1.image + c2.image);  
}  
  
Complex operator - (const Complex &c1, const Complex &c2)  
{  
    return Complex(c1.real - c2.real, c1.image - c2.image);  
}  
  
Complex operator * (const Complex &c1, const Complex &c2)  
{  
    return Complex(c1.real*c2.real - c1.image*c2.image, c1.real*c2.image + c1.image*c2.real);  
}  
  
int rev(int id, int len){ 
    int ret = 0;  
    for(int i = 0; (1 << i) < len; i++){  
        ret <<= 1;  
        if(id>>i&1) ret++;
    }  
    return ret;  
}  
  
Complex A[1 << 19];  
void FFT(Complex *a, int len, int DFT)  
{  
    for(int i = 0; i < len; i++)  
        A[rev(i, len)] = a[i];  
    for(int n = 2; n<= len; n<<=1)  
    {  
        Complex wm = Complex(cos(DFT*2*PI/n), sin(DFT*2*PI/n));  
        for(int k = 0; k < len; k += n)  
        {  
            Complex w = Complex(1, 0);  
            for(int j = k; j <k+ (n >> 1); j++)  
            {  
                Complex t = w*A[j + (n >> 1)];  
                Complex u = A[j];  
                A[j] = u + t;  
                A[j + (n >> 1)] = u - t;  
                w = w*wm;  
            }  
        }  
    }  
    if(DFT == -1) for(int i = 0; i < len; i++) A[i].real /= len, A[i].image /= len;  
    for(int i = 0; i < len; i++) a[i] = A[i];  
    return;  
}  
  
Complex S[1 << 19], H[1 << 19], C[1 << 19], D[1 << 19];  
  
int main()  
{  
    int a, b, c;  
    init();  
    while(scanf("%d %d %d", &a, &b, &c), a || b || c)  
    {  
        int len = 1;  
        while(len <= b) len <<= 1;  
        len <<= 3;  
        for(int i = 0; i <= b; i++)  
            if(!isPrime[i]) S[i] = H[i] = C[i] = D[i] = Complex(1, 0);  
            else S[i] = H[i] = C[i] = D[i] = Complex(0, 0);  
        for(int i = b + 1; i < len; i++) S[i] = H[i] = C[i] = D[i] = Complex(0, 0);  
        int num;  
        char type;  
        for(int i = 0; i < c; i++)  
        {  
            scanf("%d%c", &num, &type);  
            switch(type)  
            {  
                case 'S': S[num] = Complex(0, 0); break;  
                case 'H': H[num] = Complex(0, 0); break;  
                case 'C': C[num] = Complex(0, 0); break;  
                case 'D': D[num] = Complex(0, 0); break;  
            }  
        }  
        FFT(S, len, 1); FFT(H, len, 1); FFT(C, len, 1); FFT(D, len, 1);  
        for(int i = 0; i < len; i++)  
            S[i] = S[i]*H[i]*C[i]*D[i];  
        FFT(S, len, -1);  
        for(int i = a; i <= b; i++)  
            printf("%lld\n", (LL)(S[i].real + 0.5));  
        putchar('\n');  
    }  
    return 0;  
}  
