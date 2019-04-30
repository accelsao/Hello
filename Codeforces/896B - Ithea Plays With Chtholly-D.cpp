#include<iostream>
using namespace std;
int n, m, c, x, s, a[1001], t;
int main(){
	scanf("%d%d%d", &n, &m, &c);
	while (t<n){
		scanf("%d", &x);
		if (x*2 <= c){
			s = 1;
			while (a[s] && a[s] <= x)s++;
		}
		else{
			s = n;
			while (a[s] >= x)s--;
		}
		t += !a[s];
		a[s] = x;
		printf("%d\n", s);
		fflush(stdout);
	}
}
