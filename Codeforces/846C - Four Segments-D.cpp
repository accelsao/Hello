#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5001;
LL p[N],n,mx[N],sm,d1,d2,d3;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];p[i]+=p[i-1];
		mx[i]=p[i]>p[mx[i-1]]?i:mx[i-1];
	}
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(sm<p[mx[i]]-p[i]+p[j])
				sm=p[mx[i]]-p[i]+p[j],d1=mx[i],d2=i,d3=j;
	cout<<d1<<' '<<d2<<' '<<d3<<endl;
}
