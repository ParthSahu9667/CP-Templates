inline uint64_t combineHash(int h1, int h2) {
    return (uint64_t(h1) << 32) ^ uint64_t(h2);
}
int expo(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
int mod_add(int a, int b, int m) { return ( (a % m + b % m) % m + m) % m; }
int mod_mul(int a, int b, int m) { return ( (a % m * b % m) % m + m) % m; }
int mod_sub(int a, int b, int m) { return ( (a % m - b % m) % m + m) % m; }
int mminvprime(int a, int b) { return expo(a, b - 2, b); }
 
struct Hashing {
    vector<int> s;
    int n;
    vector<int> hashPrimes = {1000000009, 100000007};
    const int base = 31;
    vector<vector<long long>> hashValues, powersOfBase;

    Hashing(const vector<int> &a) {
        s = a;
        n = s.size();
        int primes = hashPrimes.size();
        
        hashValues.assign(primes, vector<long long>(n + 1, 0));
        powersOfBase.assign(primes, vector<long long>(n + 1, 0));

        for (int i = 0; i < primes; i++) {
            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                powersOfBase[i][j] = (powersOfBase[i][j - 1] * base) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j - 1] * base + s[j - 1]) % hashPrimes[i];
            }
        }
    }

    inline int substringHash(int l, int r) {
        int len = r - l + 1;
        long long h1 = (hashValues[0][r + 1] - (hashValues[0][l] * powersOfBase[0][len]) % hashPrimes[0] + hashPrimes[0]) % hashPrimes[0];
        long long h2 = (hashValues[1][r + 1] - (hashValues[1][l] * powersOfBase[1][len]) % hashPrimes[1] + hashPrimes[1]) % hashPrimes[1];

        return combineHash(h1, h2);
    }
};
