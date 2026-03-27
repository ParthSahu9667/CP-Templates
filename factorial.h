int N = 2e5 + 1;
vector<long long> fact(N + 1), ifact(N + 1);
long long expo(long long a, long long b, long long mod) {long long res = 1;while (b > 0){if (b & 1) res = (res * a) % mod; a = (a * a) % mod;b = b >> 1;}return res;}
long long modinv(long long a,long long m) {return expo(a,m - 2,m);}
long long mod_div(long long a, long long b, long long m) {a = a % m; b = b % m; return ((a * modinv(b, m)) % m + m) % m;}  //only for prime m
void calculate_factorials() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    ifact[N - 1] = modinv(fact[N - 1],mod);
    for (int i = N - 2; i >= 0; i--) {
        ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
    }
}
long long ncr (long long n, long long r) {
    if (r < 0 || r > n) return 0;
    if (n < r) return 0;
    if (n == r) return 1ll;
    return (((fact[n] * ifact[r]) % mod) * ifact[n - r]) % mod;
}
