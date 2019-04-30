#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,q,k,l,r;
struct Q{int l,r,id;}p[N];
long long cnt,ans[N],a[N],b[N];
bool cmp(Q a,Q b){
	int x=(a.l-1)/k,y=(b.l-1)/k;
	return x==y?a.r<b.r:x<y;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	for(int i=1;i<=q;i++)
		cin>>p[i].l>>p[i].r,p[i].id=i;
	k=sqrt(n);
	sort(p+1,p+1+q,cmp);
	l=1;
	for(int i=1;i<=q;i++){
		while(l<p[i].l)cnt-=a[l]*(--b[a[l++]]*2+1);
		while(l>p[i].l)cnt+=a[--l]*(b[a[l]]++*2+1);
		while(r<p[i].r)cnt+=a[++r]*(b[a[r]]++*2+1);
		while(r>p[i].r)cnt-=a[r]*(--b[a[r--]]*2+1);
		ans[p[i].id]=cnt;
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
}
