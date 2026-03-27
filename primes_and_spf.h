const int N = 1e5;
vector<int> prime(N + 1, 1), spf(N + 1, 0);
void calculate_primes() {
    iota(all(spf), 0);

    prime[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            prime[j] = 0;
            spf[j] = min(spf[j], i);
        }
    }
}