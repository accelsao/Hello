#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
const int N=1e5+1;
const LL M=1e18;
LL n,m,bty,inc,dmg;
int mx[N],reg[N];
vector<PLL>emy[N],cnt;//enemy {time health}
void find(LL mx,LL reg,LL H,LL T,LL nxt){//max regen health time nxt_time
	if(H>dmg)return;
	cnt.PB({T,1});
	if(reg==0||mx<=dmg){
		//cout<<T<<" "<<nxt<<endl; 
		if(~nxt)cnt.PB({nxt,-1});
		
	}
	else{
		LL pt=(dmg-H+reg)/reg;//T+pt is time that (health over dmg)
		if(~nxt)cnt.PB({min(T+pt,nxt),-1});
		else cnt.PB({T+pt,-1});
	}
}
int main(){Accel
	cin>>n>>m>>bty>>inc>>dmg;//bounty increase damage
	FOR(i,1,n){
		LL H;//mx max health H start health reg regenerate
		cin>>mx[i]>>H>>reg[i];
		emy[i].PB({0,H});
	}
	FOR(i,1,m){
		LL T,E,H;//time enemy health
		cin>>T>>E>>H;
		emy[E].PB({T,H});	
	}
	FOR(i,1,n){
		sort(ALL(emy[i]));
		for(int j=0;j<(int)emy[i].size();j++)
			find(mx[i],reg[i],emy[i][j].S,emy[i][j].F,(j+1==emy[i].size()?-1:emy[i][j+1].F));
	}
	sort(ALL(cnt));
	LL c=0,ans=0;
	REP(i,(int)cnt.size()){
		c+=cnt[i].S;
		if(i+1==(int)cnt.size()||cnt[i].F!=cnt[i+1].F)
			ans=max(ans,c*(bty+inc*(cnt[i+1].F-1)));
	}
	if(c&&inc)puts("-1");
	else cout<<ans<<endl;
}
