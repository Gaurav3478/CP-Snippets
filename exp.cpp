ll exp(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) { 
            res*=a; 
        }
        b /= 2;
        a *= a;
    }
    return res;
}
