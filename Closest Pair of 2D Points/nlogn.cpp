#include <bits/stdc++.h>
#define ld long double
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
#define SZ(a) ((int)a.size())
#define endl "\n"
//#pragma GCC optimize(2)
using namespace std;
//typedef complex<double>C;
//const double PI(acos(-1.0));
//const double eps(1e-8);
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)L

struct Point{
	int x, y;
};
bool cmp_X(const Point &a,const Point &b){
	return a.x<b.x;
}
bool cmp_Y(const Point &a,const Point &b){
	return a.y<b.y;
}
int n;
int dis(Point a,Point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
vector<Point>merge_sort(vector<Point>a){
	
	int len=a.size();
	if(len<=1){
		return a;
	}
	int m=len>>1;
	vector<Point>L,R;
	for(int i=0;i<m;i++)L.push_back(a[i]);
	for(int i=m;i<len;i++)R.push_back(a[i]);
	merge_sort(L);
	merge_sort(R);
	vector<Point>b;
	int i=0,j=m;
	while(i<m&&j<len){
		if(L[i].y<R[j].y)
			b.push_back(L[i]),i++;
		else
			b.push_back(R[j]),j++;
	}
	while(i<m)
		b.push_back(L[i]),i++;
	while(j<len)
		b.push_back(R[j]),j++;
	return b;
}
vector<Point>closest_pair(vector<Point>Px,vector<Point>Py){
	int len=Px.size();
	if(len<=3){
		int min_d=2e9,l=-1,r=-1;
		for(int i=0;i<len;i++)
			for(int j=i+1;j<len;j++){
				int d=dis(Px[i],Px[j]);
				if(d<min_d){
					min_d=d;
					l=i,r=j;
				}
			}
		vector<Point>pts;
		pts.push_back(Px[l]);
		pts.push_back(Px[r]);
		return pts;
	}
	int mid=len/2;
	vector<Point>py_l,py_r;
	vector<Point>px_l,px_r; 
	for(int i=0;i<len;i++){
		if(Py[i].x<Px[mid].x)
			py_l.push_back(Py[i]);
		else
			py_r.push_back(Py[i]);
		if(i<mid)
			px_l.push_back(Px[i]);
		else
			px_r.push_back(Px[i]);
	}

	vector<Point>p_l,p_r; 
	p_l=closest_pair(px_l,py_l);
	p_r=closest_pair(px_r,py_r);
	
	int dl,dr;
	dl=dis(p_l[0],p_l[1]);
	dr=dis(p_r[0],p_r[1]);
	int d_lr=min(dl,dr);
	
	//middle
	vector<Point>p_m;
	for(int i=0;i<len;i++)
		if(abs(Py[i].x-Px[mid].x)<d_lr)
			p_m.push_back(Py[i]);
			
	len=p_m.size();
	if(len<=1)
		return dl<dr?p_l:p_r;
	
	vector<Point>ans;
	for(int i=0;i<len;i++)
		for(int j=i+1;j<len;j++){
			if(p_m[j].y-p_m[i].y>=d_lr)break;
			int tmp=dis(p_m[j],p_m[i]);
			if(tmp<d_lr){
				d_lr=tmp;
				ans.clear();
				ans.push_back(p_m[i]);
				ans.push_back(p_m[j]);
			}
		}
	if(ans.size()>0){
		return ans;
	}
	return dl<dr?p_l:p_r;
}
int main(){Accel
//	freopen("01_nlogn.txt","w",stdout);
	cin>>n;
	vector<Point>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i].x>>a[i].y;
	
	vector<Point>Px,Py;
	Px=a;
	Py=a;
	sort(Px.begin(),Px.end(),cmp_X);
	sort(Py.begin(),Py.end(),cmp_Y);
	
//	for(int i=0;i<n;i++)
//		printf("%d %d\n",Py[i].x,Py[i].y);
	vector<Point>cls_pts = closest_pair(Px,Py);
	printf("%d %d - %d %d\n",cls_pts[0].x,cls_pts[0].y,cls_pts[1].x,cls_pts[1].y);

}

/*
5
1 20
2 65
2 9
40 9
5 10


*/
