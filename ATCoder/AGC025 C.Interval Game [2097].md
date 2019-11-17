# Problem Statement
A and B play game  
A is on 0 at first  
Given N segment [L,R]  
B choose a segment ,A will go to it  
B want to max the distance  
A will go back 0 at the end  
find the maximum of the distance A walk  
# Constraints
* <a href="https://www.codecogs.com/eqnedit.php?latex=1\leq&space;N\leq&space;10^{5}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?1\leq&space;N\leq&space;10^{5}" title="1\leq N\leq 10^{5}" /></a>
* <a href="https://www.codecogs.com/eqnedit.php?latex=-10^{5}\leq&space;L<&space;R\leq10^{5}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?-10^{5}\leq&space;L<&space;R\leq10^{5}" title="-10^{5}\leq L< R\leq10^{5}" /></a>
# Solution
Inorder  to max the dis  B will choose the max L left or the min R left  
and the total dis for it is double (go back 0)  
for each segment get L and R  
sort L lesser  
sort R greater  
remember add [0,0] because A need to go back 0  
finally while the leftmost point is on the left of the rightmost point continue add the ans  
```cpp
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);
  	cin.tie(0);
  	int n;
  	cin>>n;
  	vector<int>L(n+1),R(n+1);
  	for(int i=0;i<n;i++)
  		cin>>L[i]>>R[i];
  	sort(L.rbegin(),L.rend());
  	sort(R.begin(),R.end());
  	LL ans=0;
  	for(int i=0;i<=n;i++){
  		//cout<<L[i]<<" "<<R[i]<<endl;
  		if(L[i]<R[i])break;
	  	ans+=L[i]-R[i];
	}
	cout<<ans*2<<endl;
}
```
