vector<ll> p_pow, h;
void preProcess(string s) {
    ll n = s.size();
    p_pow.resize(n, 0);
    h.resize(n + 1, 0);
    const ll p = 31;
    p_pow[0] = 1;
    h[0] = (s[0] - 'a' + 1);
    for(ll i=1; i<n; i++) {
        char c = s[i];
        p_pow[i] = (p_pow[i-1]*p)%MOD;
        h[i] = ((h[i-1] + (c - 'a' + 1)*p_pow[i]))%MOD;
    }
}

ll hasher(ll l, ll r) {
    ll ans = h[r];
    if(l > 0) {
        ans = (ans - h[l - 1] + MOD)%MOD;
    }
    return ans;
}
