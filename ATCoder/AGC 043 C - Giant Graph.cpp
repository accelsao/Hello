// ███▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓▓▓╬╬╬╬╬╬▓█
// ███▓███████▓▓╬╬╬╬╬╬╬╬╬╬╬╬▓███▓▓▓▓█▓╬╬╬▓█
// ███████▓█████▓▓╬╬╬╬╬╬╬╬▓███▓╬╬╬╬╬╬╬▓╬╬▓█
// ████▓▓▓▓╬╬▓█████╬╬╬╬╬╬███▓╬╬╬╬╬╬╬╬╬╬╬╬╬█
// ███▓▓▓▓╬╬╬╬╬╬▓██╬╬╬╬╬╬▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
// ████▓▓▓╬╬╬╬╬╬╬▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
// ███▓█▓███████▓▓███▓╬╬╬╬╬╬▓███████▓╬╬╬╬▓█
// ████████████████▓█▓╬╬╬╬╬▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬█
// ███▓▓▓▓▓▓▓╬╬▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
// ████▓▓▓╬╬╬╬▓▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
// ███▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
// █████▓▓▓▓▓▓▓▓█▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
// █████▓▓▓▓▓▓▓██▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██
// █████▓▓▓▓▓████▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██
// ████▓█▓▓▓▓██▓▓▓▓██╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██
// ████▓▓███▓▓▓▓▓▓▓██▓╬╬╬╬╬╬╬╬╬╬╬╬█▓╬▓╬╬▓██
// █████▓███▓▓▓▓▓▓▓▓████▓▓╬╬╬╬╬╬╬█▓╬╬╬╬╬▓██
// █████▓▓█▓███▓▓▓████╬▓█▓▓╬╬╬▓▓█▓╬╬╬╬╬╬███
// ██████▓██▓███████▓╬╬╬▓▓╬▓▓██▓╬╬╬╬╬╬╬▓███
// ███████▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬████
// ███████▓▓██▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓████
// ████████▓▓▓█████▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█████
// █████████▓▓▓█▓▓▓▓▓███▓╬╬╬╬╬╬╬╬╬╬╬▓██████
// ██████████▓▓▓█▓▓▓╬▓██╬╬╬╬╬╬╬╬╬╬╬▓███████
// ███████████▓▓█▓▓▓▓███▓╬╬╬╬╬╬╬╬╬▓████████
// ██████████████▓▓▓███▓▓╬╬╬╬╬╬╬╬██████████
// ███████████████▓▓▓██▓▓╬╬╬╬╬╬▓███████████
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int M = 998244353;

string to_string(string s)
{
    return '"' + s + '"';
}
string to_string(const char* s)
{
    return to_string((string) s);
}
string to_string(bool b)
{
    return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void debug_out()
{
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
//#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    // total O(M)
    int n, m;
    cin>>n;

    vector<long long> pw(n);
    pw[0] = 1000000000000000000 % M;
    for(int i=1;i<n;i++){
        pw[i] = pw[i-1] * pw[0] % M;
    }



    int u, v;
    vector<vector<vector<int>>> mex;

    vector<int> p(3);

    vector<vector<int>> g(n, vector<int>());
    vector<int> rk(n);


    for(int j=0; j<3; j++)
    {
        for(int i=0; i<n; i++)
        {
            g[i].clear();
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v;
            u--,v--;
            if(u>v)
            {
                swap(u,v);
            }
            g[u].push_back(v);
        }

//    debug(g);
        mex.push_back(vector<vector<int>>());


        vector<int> nums(n);

        for(int i=n-1; i>=0; i--)
        {
            int num=0;
            int sz = mex[j].size();


            for(int j : g[i])
            {
                nums[rk[j]]=i+1;
            }

//            debug(nums);
            num=sz;
            for(int j=0;j<sz;j++){
                if(nums[j]!=i+1){
                    num=j;
                    break;
                }
            }
            if(num == sz)
            {
                mex[j].push_back(vector<int>());
            }
            mex[j][num].push_back(i);
            rk[i]=num;
        }
        p[j]=mex[j].size();
    }

    debug(mex);

    long long ans=0;
    for(int i=0; i<p[0]; i++)
        for(int j=0; j<p[1]; j++)
        {
            int k=i^j;
            if(k>=p[2])
                continue;
            if(mex[0][i].size()==0)
                continue;
            if(mex[1][j].size()==0)
                continue;
            if(mex[2][k].size()==0)
                continue;
            //i,j,k
            long long sum=0, tmp=1;
//    debug(mex[0][i]);
            for(int a1 : mex[0][i])
            {
                sum = sum + tmp * pw[a1] % M;
                sum %= M;
            }
            tmp = sum;

            sum = 0 ;

//    debug(mex[1][j]);
            for(int a2 : mex[1][j])
            {
                sum = sum + tmp * pw[a2] % M;
                sum %= M;
            }
            tmp = sum;

            sum = 0;
//    debug(mex[2][k]);

            for(int a3 : mex[2][k])
            {
                sum = sum + tmp * pw[a3] % M;
                sum %= M;
            }
//    debug(sum);
            ans = ans + sum;
            ans %= M;
        }
    debug(ans);
    cout << ans << "\n";

}
