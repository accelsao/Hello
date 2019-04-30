#include<bits/stdc++.h>
using namespace std;
#define LL long long
map<LL,LL>m;
int main(){
	int t,n;LL x;
	cin>>t;
	while(t--){
		m.clear();
		cin>>n;
		while(n--){
			cin>>x,m[x]++;
		}
		long long t=0,ans=1LL<<60,tmp,lef=0;
		for(auto x=m.begin() ;x!=m.end();x++){
			t+=(((x->second)-1)/(x->first)+1)*(x->first);
			lef+=x->second%x->first;
		}
		for(auto x=m.begin();x!=m.end();x++){
			tmp=t;
			if((x->second-1)%x->first==0)tmp-=x->first;
			if(lef>x->second%x->first)
				ans=min(ans,tmp);
			else ans=min(ans,tmp+1+(x->first==1));
		}
		cout<<ans<<endl;
	}	
}
