#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
stack<int>s,t;
int n,m,color[N],uesd[N],ans[N],no;
int main(){
    cin>>n>>m;no=m+1;
    for(int i=1;i<=n;i++)
        cin>>color[i];
    for(int i=0;i<=n+1;i++){
        if(uesd[color[i]]){
            int c=0;
            while(s.top()!=color[i]){
                t.push(s.top());
                c++;
                s.pop();
            }
            while(t.size()){
                ans[color[i]]=max(ans[color[i]],ans[t.top()]+c);
                t.pop();
            }
        }
        else s.push(color[i]),uesd[color[i]]=1,no--;
    }
    cout<<ans[0]+no<<endl;
}
