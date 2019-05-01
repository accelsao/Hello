#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<stack>
#include<ctime>
#include<vector>
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define LL long long
#define Re(a,b) memset(a,b,sizeof(a))
#define N 1100000
#define M
#define scanf scanf_s
using namespace std;

int B[1 << 13], D[1 << 13], n;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> B[i];
	for (int i = 0; i < n; i++)
		cin >> D[i];
	if (B[1] != D[1])puts("-1");
	else{ cout << 2 * n - 3 << endl;
	for (int i = 1; i < n; i++)
		cout << "1 " << B[i] << endl;
	for (int i = 2; i < n; i++)
		cout << D[i - 1] << ' ' << D[i] << endl;}
}
