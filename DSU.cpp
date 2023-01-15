class DSU {
private:
    vector<ll> parent, size;
public:
    DSU(ll n) {
        parent = vector<ll>(n);
        size = vector<ll>(n, 1);
        iota(begin(parent), end(parent), 0);
    }
    
    ll getParent(ll x) {
        if (parent[x] == x) return x;
        return parent[x] = getParent(parent[x]);
    }

    void join(ll x, ll y) {
        x = getParent(x);
        y = getParent(y);
        if (size[x] > size[y])
            swap(x, y);
        if (x == y) return;
        parent[x] = y;
        size[y] += size[x];
    }

    ll getSize(ll x) {
        return size[x] = size[getParent(x)];
    }
};
