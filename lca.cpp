int LOG = 20;
vector<vector<int>> up(n, vector<int> (LOG + 1, 0));
vector<int> depth(n, 0);
auto dfs1 = [&](auto &&dfs1, int v, int par) -> void {
    up[v][0] = par;
    for(int i = 1; i <= LOG; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    
    for(auto ch: adj[v]) {
        if(ch != par) {
            depth[ch] = 1 + depth[v];
            dfs1(dfs1, ch, v);
        }
    }
};
dfs1(dfs1, 0, 0);

auto kth = [&](int v, int k) {
    for(int i = 0; i <= LOG; i++) {
        if(k & (1 << i)) {
            v = up[v][i];
        }
    }
    return v;
};

auto get_lca = [&](int u, int v) {
    if(depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    u = kth(u, diff);

    if(u == v) {
        return u;
    }

    for(int i = LOG; i >= 0; i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
};

auto dist = [&](int u, int v) {
    return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
};
