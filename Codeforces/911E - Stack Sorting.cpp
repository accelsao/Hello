#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,k,a[N],t=1;
stack<int>s;
int main(){
	cin>>n>>k;
	s.push(n+1);
	for(int i=0;i<n;i++){
		if(i<k)cin>>a[i];
		else a[i]=s.top()-1;
		s.push(a[i]);
		while(s.size()&&s.top()==t)s.pop(),t++;
	}
	if(s.size())puts("-1");
	else for(int i=0;i<n;i++)cout<<a[i]<<' ';
}
