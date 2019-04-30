#include<iostream>
#include<algorithm>
#define M 200000*30
using namespace std;
int dep[M], ls[M], rs[M], c = 1, n, x;
long long O;
int F(int u, int v, int d) {
	if (!d)
		return 0;
	int O = 1 << d;
	if (ls[u] && ls[v])//如果兩數的這個位置上的數都是0
		O = min(O, F(ls[u], ls[v], d - 1));
	if (rs[u] && rs[v])//如果都是1
		O = min(O, F(rs[u], rs[v], d - 1));
	if (O < 1 << d)
		return O;
	//一個0一個1 的情況
	if (ls[u] && rs[v])
		return F(ls[u], rs[v], d - 1) | 1 << d - 1;
	if (rs[u] && ls[v])
		return F(rs[u], ls[v], d - 1) | 1 << d - 1;
	return O;
}
int main() {
	cin >> n;
	dep[1] = 30;
	//建立01字典樹 將數字看成01字串處理
	for (int i = 1; i <= n; i++) {
		cin >> x;
		for (int p = 1, d = 29; ~d; d--) {
			int &son = (x >> d & 1 ? rs : ls)[p];
			if (!son)
				dep[son = ++c] = d;
			p = son;
		}
	}
	for (int i = 1; i <= c; i++) 
		if (ls[i] && rs[i]) //這個bit 有0有1
			O += (1 << dep[i] - 1) + F(ls[i], rs[i], dep[i] - 1);//先加上這個bit+ 低位 最小可能數字 (挑同數字 xor值才會小 跟找Trie一樣)
	cout << O;
}
----
將數字轉成bit 做01 Trie
4
3 5 6 8
0011
0101
0110
1000

從最高位開始
題目要求MinST 權重2數Xor 
所以從高位到低位 第一個不同的數 越低越好

測資 從第4位 有不同
1000
0XXX
先加上 1<<4-1
在遞歸低位的數
1000
0XXX
 ^
 | 
第3位 是0比較好
所以取
1000
0011 只剩這個 所以不用再找 +3
目前8+3
再找 第3位 也有0有1
先加上 1<<3-1
1XX
0XX
最佳
1000
0101 
再加上1
目前:11+4+1
以此類推
最後
0101
0110
#前面2個都是01
1<<2-1 + 1
=19
注意:找第i位時 前面的數都要一樣
所以就跟找字典樹一樣意思
----
#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=2e5*30;
LL dep[N],x,n,sz,l[N],r[N],ans;
int F(int u,int v,int d){
	if(!d)return 0;
	int s=1<<d;
	if(l[u]&&l[v])s=F(l[u],l[v],d-1);
	if(r[u]&&r[v])s=min(s,F(r[u],r[v],d-1));
	if(s<1<<d)return s;
	if(l[u]&&r[v])
		return F(l[u],r[v],d-1)|1<<d-1;
	if(r[u]&&l[v])
		return F(r[u],l[v],d-1)|1<<d-1;
}
int main(){
	cin>>n;
	dep[0]=30;
	for(int i=0;i<n;i++){
		cin>>x;
		for(int j=0,d=29;~d;d--){
			LL &s=(x>>d&1?r:l)[j];
			if(!s)
				dep[s=++sz]=d;
			j=s;
		}
	}
	for(int i=0;i<=sz;i++)
		if(l[i]&&r[i])
			ans+=(1<<dep[i]-1)+F(l[i],r[i],dep[i]-1);
	cout<<ans<<endl;
}
