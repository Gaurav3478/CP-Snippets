vector<int> primes;
vector<bool> is_prime;

void Sieve() {
    is_prime.resize(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && (ll)i * i <= N) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }

    for(ll i = 2; i <= N; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
        }
    }
}
