#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define F first
#define S second
using ll = long long ;
const int N = 1e6 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18; 
//typedef complex<double> C;
using C = complex<double>;

C a, b, w1, w2, m1, m2;

double dot(const C& a, const C& b){
	return real(a*conj(b));
}
double det(const C& a, const C& b){
	return -imag(a*conj(b));
}
C sym(const C& x, const C& a, const C& b){
	return x + 2*dot(a,b)/dot(b,b)*b - a;
//	return x + 2 * (dot(a,b)/dot(b,b)*b) - a;
}
bool onSeg(const C& p, const C& a, const C& b){
	return det(a-p, b-p)==0 && dot(a-p, b-p)<=0;
}
int intersect(const C& a, const C& b, const C& c, const C& d){
	double t1 = det(c-a, b-a)*det(b-a, d-a);
	double t2 = det(a-c, d-c)*det(d-c, b-a);
	if(t1<0||t2<0)return 0;// no intersect
	if(t1==0&&t2==0){ // colinear
		return onSeg(a, c, d)||onSeg(b, c, d)||onSeg(c, a, b);
	}
	if(t1==0||t2==0){// check wall
		return 2;
	}
	return 3; // intersect
}
bool check(){
	int stat=intersect(a, b, m1, m2);
	if(stat==3){ 
		return 0; 
	}
	else if(stat==2||stat==1){
		return intersect(a, b, w1, w2)==0;
	}
	else{
		stat = intersect(a, b, w1, w2);
		if(stat==0){
			return 1;
		}
		else{
			C A=sym(m1, a-m1, m2-m1);
			C B=sym(m1, b-m1, m2-m1);
			return intersect(A, b, m1, m2)==3 && !intersect(A, b, w1, w2)==0 && !intersect(a, B, w1, w2);
		}
	}
			
}
	
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int x, y;
	cin>>x>>y;
	a={x, y};
	cin>>x>>y;
	b={x, y};
	cin>>x>>y;
	w1={x, y};
	cin>>x>>y;
	w2={x, y};
	cin>>x>>y;
	m1={x, y};
	cin>>x>>y;
	m2={x, y};
	if(check()){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
	
}

