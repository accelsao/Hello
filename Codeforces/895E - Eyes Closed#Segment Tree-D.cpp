#include<iostream>
using namespace std;
#define N 400101
#define m (l+r>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define ls lc,l,m
#define rs rc,m+1,r
#define up sm[rt] = sm[lc] + sm[rc]
#define st 1,1,n
#define lg ls,L,R
#define rg rs,L,R
int n, q, ty, l1, r1, l2, r2, a, b, sl[N];
double L1, L2, tot, sm[N], mul[N], ad[N], s1, s2;
void build(int rt=1, int l=1, int r=n) {
	ad[rt] = 0, mul[rt] = 1, sl[rt] = r - l + 1;
	if (l == r) {
		cin >> sm[rt]; return;
	}
	build(ls); build(rs);
	up;
}
void mk(int rt, double a, double b){
	sm[rt] = sm[rt] * a + sl[rt] * b;
	ad[rt] = ad[rt] * a + b;
	mul[rt] *= a;
}
void pd(int rt){
	if (mul[rt] != 1 || ad[rt]){
		if (rt>1)mk(lc, mul[rt], ad[rt]), mk(rc, mul[rt], ad[rt]);
		mul[rt] = 1, ad[rt] = 0;
	}
}
double sum(int rt,int l, int r, int L, int R) {
	if (l > R || r < L)return 0;
	if (L <= l&&r <= R)
		return sm[rt];
	pd(rt);
	return sum(lg) + sum(rg);
}

void update(int rt, int l, int r, int L, int R, double a,double b) {//a乘法 b 加法
	if (l > R || r < L)return;
	if (L <= l&&r <= R){
		mk(rt, a, b); return;
	}
	pd(rt);
	update(lg, a, b), update(rg, a, b);
	up;
}
int main() {
	cin >> n >> q;
	build();
	while (q--) {
		cin >> ty >> l1 >> r1;
		if (ty < 2) {
			cin >> l2 >> r2;
			s1 = sum(st, l1, r1), s2 = sum(st, l2, r2);
			L1 = r1 - l1 + 1; L2 = r2 - l2 + 1;
			update(st, l1, r1, 1 - 1.0 / L1, s2 / L1 / L2);
			update(st, l2, r2, 1 - 1.0 / L2, s1 / L1 / L2);
		}
		else 
			printf("%lf\n", sum(st, l1, r1));
	}
}
//
題意:
兩個操作
1. l1,r1 l2r2 區間內各自隨機取一個數 交換
2. l,r 區間期望值多少

先考慮左區間 總和s1,長度L1
右 s2,L2

對左區間取x
期望值
(L1-1 )/L1*x(沒被交換的區間L1-1) + 1/L1*(s2/L2)(被交換的1個)
右區間同理
L2-1 / L2*x + 1/L2 *s1/L1
(a      )*x + b
處理時 對x 做乘法和加法維護
主要在mk的function
其餘線段樹處理區間sum
//
