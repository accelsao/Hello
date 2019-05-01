#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    long long ans = 1LL * n * (n - 1) * (n - 2) / 6;//c(n,3)
    long long bad = 0;
    int n2 = (n-1) / 2;//n-1 degree
    //n*( [c(in,2)+c(out,2)] /2)
    bad = 1LL * n * ((n2 * (n2 - 1) / 2) + ((n-1) - n2) * ((n-1) - n2 - 1) / 2);
    bad /= 2;
    cout << (ans - bad)<<endl;
    for (int i =n-1;i;i--) {//n-1 times
        //n2=i/2;
        cout << string(i-n2, '1') << string(n2, '0');
        n2=max(0,n2-1);
    }
}
