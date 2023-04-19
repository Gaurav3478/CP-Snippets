int MAXN = 1e6 + 5;
vector<int> spf(MAXN + 1, 1);
vector<int> primes;
void Sieve() {
    for(int i = 2; i <= MAXN; i++) {
        if(spf[i] == 1) {
            primes.push_back(i);
            for(int j = i; j <= MAXN; j += i) {
                spf[j] = i;
            }
        }
    }
}    

vector<int> factorize(int x) {
    vector<int> prime_factors;
    while(x > 1) {
        prime_factors.push_back(spf[x]);
        x /= spf[x];
    }
    return prime_factors;
}
