// �i�i�i�������������������������������������������������������������������������i
// �i�i�i���i�i�i�i�i�i�i�������������������������������i�i�i���������i�����������i
// �i�i�i�i�i�i�i���i�i�i�i�i�����������������������i�i�i�������������������������i
// �i�i�i�i���������������i�i�i�i�i������������i�i�i����������������������������i
// �i�i�i�����������������������i�i�����������������������������������������������i
// �i�i�i�i�����������������������i�����������������������������������������������i
// �i�i�i���i���i�i�i�i�i�i�i�����i�i�i�����������������i�i�i�i�i�i�i�������������i
// �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i���i������������������������������������������i
// �i�i�i�����������������������������i�������������������������������������������i
// �i�i�i�i���������������������������i�������������������������������������������i
// �i�i�i���i���������������������������������������������������������������������i
// �i�i�i�i�i�����������������i�������i�������������������������������������������i
// �i�i�i�i�i���������������i�i�������i����������������������������������������i�i
// �i�i�i�i�i�����������i�i�i�i�������i����������������������������������������i�i
// �i�i�i�i���i���������i�i���������i�i����������������������������������������i�i
// �i�i�i�i�����i�i�i���������������i�i��������������������������i�������������i�i
// �i�i�i�i�i���i�i�i�����������������i�i�i�i������������������i���������������i�i
// �i�i�i�i�i�����i���i�i�i�������i�i�i�i�����i���������������i��������������i�i�i
// �i�i�i�i�i�i���i�i���i�i�i�i�i�i�i�������������������i�i�������������������i�i�i
// �i�i�i�i�i�i�i���i�i����������������������������������������������������i�i�i�i
// �i�i�i�i�i�i�i�����i�i���������������������������������������������������i�i�i�i
// �i�i�i�i�i�i�i�i�������i�i�i�i�i���������������������������������������i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�������i�����������i�i�i���������������������������i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�������i�����������i�i�������������������������i�i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�i�����i���������i�i�i�����������������������i�i�i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�i�i�i�i�������i�i�i��������������������i�i�i�i�i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�������i�i�������������������i�i�i�i�i�i�i�i�i�i�i
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int M = 1e9 + 7;

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
#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

struct SegTree
{
    int n;
    vector<int> a;
    SegTree(int _n) : n(_n)
    {
        a.resize(n + n);
    }
    SegTree(const vector<int>& vec)
    {
        n = vec.size();
        a.resize(n + n);
        for(int i=0; i<n; i++)
        {
            a[i+n] = vec[i];
        }
        for(int i=n-1; i>0; i--)
        {
            a[i] = a[i<<1] | a[i<<1|1];
        }
    }

    // assign
    void modify(int p, int value)
    {
        a[p+=n] = value;
        while(p>1)
        {
            a[p>>1] = a[p] | a[p^1];
            p>>=1;
        }
    }

    // [l, r)
    int query(int l, int r)
    {
        int res=0;
        for(l+=n, r+=n; l<r; l>>=1,r>>=1)
        {
            if(l&1)
            {
                res |= a[l];
                l++;
            }
            if(r&1)
            {
                r--;
                res |= a[r];
            }
        }
//        debug(res);
        return count_bits(res);
    }

    inline int count_bits(int x)
    {
        int cnt=0;
        while(x)
        {
            cnt++;
            x^=x&-x;
        }
        return cnt;
    }
};

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        a[i] = 1<<(s[i]-'a');
    }
    SegTree seg(a);

    int q;
    cin>>q;
    int op, l, r;
    char ch;
    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>l>>ch;
            l--;
            seg.modify(l, 1<<(ch-'a'));
        }
        else
        {
            cin>>l>>r;
            l--;
            cout << seg.query(l, r) << "\n";
        }
    }
}
