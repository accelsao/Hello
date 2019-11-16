// �i�i�i�������������������������������������������������������������������������i
// �i�i�i���i�i�i�i�i�i�i�������������������������������i�i�i���������i�����������i
// �i�i�i�i�i�i�i���i�i�i�i�i�����������������������i�i�i�������������������������i
// �i�i�i�i���������������i�i�i�i�i������������i�i�i����������������������������i
// �i�i�i�����������������������i�i�����������������������������������������������i
// �i�i�i�i�����������������������i�����������������������������������������������i
// �i�i�i���i���i�i�i�i�i�i�i�����i�i�i�����������������i�i�i�i�i�i�i�������������i
// �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i���i������������������������������������������i
// �i�i�i�����������������������������i�������������������������������������������i
// �i�i�i�i���������������������������i�������������������������������������������i
// �i�i�i���i���������������������������������������������������������������������i
// �i�i�i�i�i�����������������i�������i�������������������������������������������i
// �i�i�i�i�i���������������i�i�������i����������������������������������������i�i
// �i�i�i�i�i�����������i�i�i�i�������i����������������������������������������i�i
// �i�i�i�i���i���������i�i���������i�i����������������������������������������i�i
// �i�i�i�i�����i�i�i���������������i�i��������������������������i�������������i�i
// �i�i�i�i�i���i�i�i�����������������i�i�i�i������������������i���������������i�i
// �i�i�i�i�i�����i���i�i�i�������i�i�i�i�����i���������������i��������������i�i�i
// �i�i�i�i�i�i���i�i���i�i�i�i�i�i�i�������������������i�i�������������������i�i�i
// �i�i�i�i�i�i�i���i�i����������������������������������������������������i�i�i�i
// �i�i�i�i�i�i�i�����i�i���������������������������������������������������i�i�i�i
// �i�i�i�i�i�i�i�i�������i�i�i�i�i���������������������������������������i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�������i�����������i�i�i���������������������������i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�������i�����������i�i�������������������������i�i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�i�����i���������i�i�i�����������������������i�i�i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�i�i�i�i�������i�i�i��������������������i�i�i�i�i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�������i�i�������������������i�i�i�i�i�i�i�i�i�i�i
#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define RE(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define SZ(x) ((int)(x.size()))
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
using C = complex<double>;
const double PI = 3.14159265;
const double eps = 1e-8;
const int N = 1e6 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}

C p, v, m1, m2, w1, w2;

double dot(C a, C b){
	return real(a*conj(b));
}
double det(C a, C b){
	return -imag(a*conj(b));
}
C symmetric(C x, C a, C b){
	return x + 2 * dot(a, b) / dot(b, b) * b - a;
}
bool in(C x, C a, C b){
	return det(a-x, b-x) == 0 && dot(a-x, b-x) <= 0;
}
bool intersect(C a, C b, C c, C d){
	double t1 = det(c-a, b-a) * det(b-a, d-a);
	double t2 = det(a-c, d-c) * det(d-c, b-c);
	if(t1<0 || t2<0){
		return 0;
	}
	if(t1==0 && t2==0){
		return in(a, c, d) || in(b, c, d) || in(c, a, b);
	}
	return 1;
}
bool check(){
	if(intersect(p, v, m1, m2)){
		return det(p-v, m1-m2)==0 && !intersect(p, v, w1, w2);
	}
	if(intersect(p, v, w1, w2)){
		C symP=symmetric(m1, p-m1, m2-m1);
		C symV=symmetric(m1, v-m1, m2-m1);
		return intersect(symP, v, m1, m2) && !intersect(symP, v, w1, w2) && !intersect(p, symV, w1, w2);
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	double x, y;
	cin>>x>>y;
	v=C(x, y);
	cin>>x>>y;
	p=C(x, y);
	cin>>x>>y;
	w1=C(x, y);
	cin>>x>>y;
	w2=C(x, y);
	cin>>x>>y;
	m1=C(x, y);
	cin>>x>>y;
	m2=C(x, y);
	puts(check()?"YES":"NO");
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/



