const int mod = 1e9 + 7;

struct Mint {
    int val;

    Mint(long long v = 0) {
        if (v < 0) v = v % mod + mod;
        if (v >= mod) v %= mod;
        val = (v);
    }

    operator int() const { return val; }

    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= mod) val -= mod;
        return *this;
    }

    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += mod;
        return *this;
    }

    Mint& operator*=(const Mint &other) {
        val = (long long)val * other.val % mod;
        return *this;
    }

    Mint pow(long long exp) const {
        Mint res = 1, base = val;
        while (exp > 0) {
            if (exp % 2) res *= base;
            base *= base;
            exp /= 2;
        }
        return res;
    }

    Mint inv() const {
        return pow(mod - 2);
    }

    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }

    friend Mint operator+(Mint a, const Mint &b) { return a += b; }
    friend Mint operator-(Mint a, const Mint &b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint &b) { return a /= b; }
};