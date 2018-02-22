#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MIN(x,y) x=min(x,y)
using namespace std;

typedef long long LL;

const int N=1e4+1;
const LL inf=1e18;

int n,m,a[N],que[N];
LL f[N][105];
struct line{LL k,b;}p[N];

bool cmp(line a,line b)
{
    return a.k>b.k||a.k==b.k&&a.b<b.b;
}

double get_pts(line x,line y)
{
    return (double)(y.b-x.b)/(x.k-y.k);
}

void solve(int l,int r)
{
    if (l==r) return;
    int mid=(l+r)/2;
    solve(l,mid);
    for (int j=1;j<m;j++)
    {
        int tot=0;
        for (int i=l;i<=mid;i++)
            p[++tot].k=-2*a[i+1],p[tot].b=(LL)a[i+1]*a[i+1]+f[i][j];
        sort(p+1,p+tot+1,cmp);
        int top=0;
        for (int i=1;i<=tot;i++)
        {
            if (i>1&&p[i].k==p[i-1].k) continue;
            while (top>1&&get_pts(p[i],p[que[top-1]])<=get_pts(p[que[top]],p[que[top-1]])) top--;
            que[++top]=i;
        }
        for (int i=mid+1;i<=r;i++)
        {
            int L=1,R=top-1;
            while (L<=R)
            {
                int mid=(L+R)/2;
                if ((LL)p[que[mid+1]].k*a[i]+p[que[mid+1]].b<(LL)p[que[mid]].k*a[i]+p[que[mid]].b) L=mid+1;
                else R=mid-1;
            }
            //if(L==top){cout<<"-1";}
            MIN(f[i][j+1],(LL)p[que[L]].k*a[i]+p[que[L]].b+(LL)a[i]*a[i]);
        }
    }
    solve(mid+1,r);
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            f[i][j]=inf;
    for (int i=1;i<=n;i++) f[i][1]=(LL)(a[i]-a[1])*(a[i]-a[1]);
    solve(1,n);
    printf("%lld",f[n][m]);
}
