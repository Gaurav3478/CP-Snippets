template<typename T>
class segtree {
    public:
    vector<T> t;
    ll n;
    T def;
    function<T(T, T)> fx;
    void build(ll _n, T _def, function<T(T, T)> _fx) {
        n = _n, def = _def, fx = _fx;
        t.assign(n * 2, def);
        for(ll i = n - 1; i; i--) t[i] = fx(t[i * 2], t[i * 2 + 1]);
    }
    void build(vector<T>& a, T _def, function<T(T, T)> _fx) {
        n = a.size(), def = _def, fx = _fx;
        t.assign(n * 2, def);
        for(ll i = 0; i < n; i++) t[i + n] = a[i];
        for(ll i = n - 1; i; i--) t[i] = fx(t[i * 2], t[i * 2 + 1]);
    }
    void update(ll i, T v) {
        for(t[i += n] = v; i > 1; ) {
            i /= 2;
            t[i] = fx(t[i * 2], t[i * 2 + 1]);
        }
    }
    // this query is made on [l, r)
    T query(ll l, ll r) {
        T lans = def, rans = def;
        for(l += n, r += n; l < r; l /= 2, r /= 2) {
            if(l % 2) lans = fx(lans, t[l++]);
            if(r % 2) rans = fx(t[--r], rans);
        }
        return fx(lans, rans);
    }
};
