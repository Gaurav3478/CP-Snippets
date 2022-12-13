int MAXN = 1e7 + 5;
vector<int> spf(MAXN + 1, 1);

void Sieve() {
    for(int i = 2; i <= MAXN; i+=2) {
        spf[i]=2;
    }

    for(int i = 3; i <= MAXN; i+=2) {
        if(spf[i] == 1) {
            for(int j = i; j <= MAXN; j += i) {
                if(spf[j] == 1) {
                    spf[j] = i;
                }
            }
        }
   }
}

vector<int> primeFactorization(int n) {
    vector<int> primes;
    while (n > 1) {
        int fact = spf[n];
        while (n % fact == 0) {
            n /= fact;
        }
        primes.push_back(fact);
    }
    return primes;
}
