#Precode for VS
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
----
#Fast power algorithm
LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1) % M : pw(a*a%M, b >> 1) : 1; }
----
#GCD
int gcd(int a, int b) { return b ? gcd(b, a%b) : a };
----
#EXGCD for py
def ext_euclid(a, b):
    if (b == 0):
        return 1, 0, a
    else:
        x, y, q = ext_euclid(b, a % b) 
        x, y = y, (x - (a // b) * y)
        return x, y, q
ext_euclid(a,b) return x,y,gcd(a,b) ,ax+by=1
----
#Devc++
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
const int N=2e5+1;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln()
int main(){Accel
}
