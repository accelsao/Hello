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
const int N = 1<<20;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}

int n, q;
int a[N];

struct Item{
	int a[2];
	Item() {
		a[0]=0;
		a[1]=1;
	}
	Item(int x, int y){
		a[0]=x, a[1]=y;
	}
	Item operator * (const Item &I) const {
		Item tmp = Item();
		tmp.a[0] = I.a[a[0]];
		tmp.a[1] = I.a[a[1]];
		return tmp;
	}
};

struct Node{
	int l, r;
	Item val;
	
	Node() : l(), r(), val() {}
	Node(int _l, int _r) : l(_l), r(_r), val() {}
}seg[N<<1];

void build(){
	for(int i=0;i<N;i++)
		seg[i+N]=Node(i, i+1);
	for(int i=N-1;i;i--){
		seg[i]=Node(seg[i<<1].l, seg[i<<1|1].r);
	}
}

void push(int u){
	seg[u<<1].val = seg[u<<1].val * seg[u].val;
	seg[u<<1|1].val = seg[u<<1|1].val * seg[u].val;
	seg[u].val = Item();
}

void modify(int u, int l, int r, Item I){
	if(seg[u].l>=r||seg[u].r<=l)return ;
	if(seg[u].l>=l&&seg[u].r<=r){
		seg[u].val = seg[u].val * I;
		return ;
	}
	push(u);
	modify(u<<1, l, r, I);
	modify(u<<1|1, l, r, I);	
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	build();
	char op;
	int x;
	while(q--){
		cin>>op>>x;
		Item I = Item();
		if(op=='>'){
			if(x>=0){
				I = Item(1, 1);
				modify(1, x+1, N, I);
			}
			else{
				I = Item(1, 0);
				modify(1, 0, -x, I);
				I = Item(1, 1);
				modify(1, -x, N, I);
			}
			
		}
		else {
			if(x<0){
				I = Item(0, 0);
				modify(1, -x+1, N, I);
			}
			else{
				I = Item(1, 0);
				modify(1, 0, x, I);
				I = Item(0, 0);
				modify(1, x, N, I);
			}
		}
	}
	
	for(int i=1;i<N;i++)
		push(i);
	
	for(int i=0;i<n;i++){
		if(a[i]<0){
			if(!seg[-a[i]+N].val.a[1]){
				a[i]=-a[i];
			}
		}
		else{
			if(seg[a[i]+N].val.a[0]){
				a[i]=-a[i];
			}
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
	
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/



