#Fast power algorithm
LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1) % M : pw(a*a%M, b >> 1) : 1; }
#GCD
int gcd(int a, int b) { return b ? gcd(b, a%b) : a };
