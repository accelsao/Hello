#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,q,p,B[1<<18],l,r,lgn,v[N];
string s;
char x;
set<int>st[128];
void add(int p,int v){while(p<=lgn*2)B[p]+=v,p+=p&-p;}
int find(int p){
	int s=0;
	for(int i=lgn;i;i>>=1)
		if(B[s+i]<p)
			s+=i,p-=B[s];
	return s+1;
}
int main(){
	cin>>n>>q>>s;
	lgn=log(n)/log(2);lgn=1<<lgn;
	for(auto x:s)st[x].insert(++p),add(p,1);
	while(q--){
		cin>>l>>r>>x;l=find(l),r=find(r);
		auto it=st[x].lower_bound(l);
		while(it!=st[x].end()&&*it<=r)
			v[*it]=1,add(*it,-1),st[x].erase(it++);
	}
	for(int i=1;i<=n;i++)
		if(!v[i])putchar(s[i-1]);
	puts("");
}
