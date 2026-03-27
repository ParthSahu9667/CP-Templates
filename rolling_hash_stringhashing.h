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
    string s;
    int n;
    vector<int> hashPrimes = {1000000009, 100000007};
    const int base = 31;
    vector<vector<int>> hashValues, powersOfBase, inversePowersOfBase;
 
    Hashing(const string &a) {
        s = a;
        n = s.size();
        int primes = hashPrimes.size();
        hashValues.assign(primes, vector<int>(n));
        powersOfBase.assign(primes, vector<int>(n + 1));
        inversePowersOfBase.assign(primes, vector<int>(n + 1));
 
        for (int i = 0; i < primes; i++) {
            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                powersOfBase[i][j] = (powersOfBase[i][j - 1] * base) % hashPrimes[i];
            }
 
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for (int j = n - 1; j >= 0; j--) {
                inversePowersOfBase[i][j] = (inversePowersOfBase[i][j + 1] * base) % hashPrimes[i];
            }
        }
 
        for (int i = 0; i < primes; i++) {
            for (int j = 0; j < n; j++) {
                hashValues[i][j] = ((s[j] - 'a' + 1) * powersOfBase[i][j]) % hashPrimes[i];
                if (j > 0) {
                    hashValues[i][j] = (hashValues[i][j] + hashValues[i][j - 1]) % hashPrimes[i];
                }
            }
        }
    }
 
    inline int substringHash(int l, int r) {
        int h1 = mod_sub(hashValues[0][r], (l ? hashValues[0][l - 1] : 0), hashPrimes[0]);
        h1 = mod_mul(h1, inversePowersOfBase[0][l], hashPrimes[0]);
 
        int h2 = mod_sub(hashValues[1][r], (l ? hashValues[1][l - 1] : 0), hashPrimes[1]);
        h2 = mod_mul(h2, inversePowersOfBase[1][l], hashPrimes[1]);
 
        return combineHash(h1, h2);
    }
};