#Precode
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<stack>
#include<ctime>
#include<vector>
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define LL long long
#define Re(a,b) memset(a,b,sizeof(a))
#define N 1100000
#define M
#define scanf scanf_s
using namespace std;
int main(){
Accel;
}
#Fast power algorithm
LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1) % M : pw(a*a%M, b >> 1) : 1; }
#GCD
int gcd(int a, int b) { return b ? gcd(b, a%b) : a };
#EXGCD 求二元一次方程式 -898B - Proper Nutrition-
def ext_euclid(a, b):
    if (b == 0):
        return 1, 0, a
    else:
        x, y, q = ext_euclid(b, a % b) 
        x, y = y, (x - (a // b) * y)
        return x, y, q
n=int(input())
a=int(input())
b=int(input())
x,y,d=ext_euclid(a,b)
if n%d:print('NO')
else:
    x*=n//d;y*=n//d
    a//=d;b//=d
    if x<0:
        f=-x//b+(-x%b!=0)
        x+=f*b;y-=f*a
    elif y<0:
        f=-y//a+(-y%a!=0)
        x-=f*b;y+=f*a
    print(['NO','YES\n'+str(x)+'  '+str(y)][x*y>=0])
