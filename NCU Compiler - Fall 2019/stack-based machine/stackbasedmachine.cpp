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
#define DEBUG
#define RE(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define SZ(x) ((int)(x.size()))
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
using C = complex<double>;
const double PI = 3.14159265;
const double eps = 1e-8;
const int N = 1e6 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}

string to_string(string s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s, op;
	int num = -1;
	stack<int> stk;
	int ans = 0;
	bool flag = 0;
	int op1, op2;
	while(getline(cin, s)){
        if(flag)continue;
        num = -1;
        stringstream ss(s);
        ss >> op;
        if(!ss.str().empty()){
            ss >> num;
        }
//        debug(op, num);

        if(op == "load"){
            stk.push(num);
        }
        else if(op == "add"){
            if(stk.size() < 2){
                flag = 1;
                continue;
            }
            op1 = stk.top();stk.pop();
            op2 = stk.top();stk.pop();
            stk.push(op1 + op2);
        }
        else if(op == "sub"){
            if(stk.size() < 2){
                flag = 1;
                continue;
            }
            op1 = stk.top();stk.pop();
            op2 = stk.top();stk.pop();
            stk.push(op1 - op2);
        }
        else if(op == "mul"){
            if(stk.size() < 2){
                flag = 1;
                continue;
            }
            op1 = stk.top();stk.pop();
            op2 = stk.top();stk.pop();
            stk.push(op1 * op2);
        }
        else if(op == "mod"){
            if(stk.size() < 2){
                flag = 1;
                continue;
            }
            op1 = stk.top();stk.pop();
            op2 = stk.top();stk.pop();
            if(op2 == 0){
                flag = 1;
            }
            else{
                stk.push(op1 % op2);
            }
        }
        else if(op == "inc"){
            op1 = stk.top();stk.pop();
            stk.push(op1 + 1);
        }
        else if(op == "dec"){
            op1 = stk.top();stk.pop();
            stk.push(op1 - 1);
        }
        else{
            flag = 1;
        }
	}
	if(flag || stk.size() != 1){
        cout << "Invalid format\n";
	}
	else{
        cout << stk.top() << "\n";
	}

}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif

load 1
load 2
sub
load 5
mod

load 1
load 2
mul
load 5
mod

*/
