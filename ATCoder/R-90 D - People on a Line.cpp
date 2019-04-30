#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,z,f[100005],w[100005];
void find(int x){
	if (f[x]==x) return;
	find(f[x]); w[x]+=w[f[x]]; f[x]=f[f[x]];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) f[i]=i;
	for (int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		find(x); find(y);
		if (f[x]==f[y]){
			if (w[x]+z!=w[y]){
				puts("No"); return 0;
			}
		}else{
			w[f[y]]=w[x]-w[y]+z;//w 相當於到他的頭的距離 現在要把x接在 y的頭 w[x]-w[y]  所以接完後的距離為 w[x]+d -w[y](相當於y距離他的頭的距離)
			f[f[y]]=f[x];
		}
	}
	puts("Yes");
	return 0;
}
