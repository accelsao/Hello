快速冪
LL pw(LL a, LL b) { return b ? b & 1 ? a*pw(a, b - 1) % y : pw(a*a%y, b >> 1) : 1; }
GCD
int gcd(int a, int b) { return b ? gcd(b, a%b) : a };
