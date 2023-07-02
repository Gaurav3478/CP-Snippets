vector<int> primes;
vector<bool> is_prime;

void Sieve(int n) {
    is_prime.resize(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (ll)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
        }
    }
}
