int gcd(int a,int b) { if (b==0) return a; return gcd(b, a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
bool isPrime(long long a) {if (a == 1) return 0;for (int i = 2; i*i <= a; ++i) if (a % i == 0) return 0; return 1;}
long long expo(long long a, long long b, long long mod) {long long res = 1;while (b > 0){if (b & 1) res = (res * a) % mod; a = (a * a) % mod;b = b >> 1;}return res;}
long long modinv(long long a,long long m) {return expo(a,m - 2,m);}
long long mod_div(long long a, long long b, long long m) {a = a % m; b = b % m; return ((a * modinv(b, m)) % m + m) % m;}  //only for prime m
