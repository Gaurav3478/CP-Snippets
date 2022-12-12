ll MAXN = 10000005;
vector<ll> spf(MAXN + 1, 1);

void Sieve() {
    for(ll i = 2, i <= MAXN, i++) {
        if (spf[i] == 1) {
            spf[i] = i;
            for (ll j = i * i; j <= N; j += i) {
                if (spf[j] == 1) {
                    spf[j] = i;
                }
        }
    }
}

vector<ll> primeFactorization(ll n) {
    vector<ll> primes;
    while (n > 1) {
        ll fact = spf[n];
        while (n % fact == 0) {
            n /= fact;
        }
        primes.push_back(fact);
    }
    return ans;
}
