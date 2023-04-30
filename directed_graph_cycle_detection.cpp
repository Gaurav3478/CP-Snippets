bool isCyclic(int V, vector<int> adj[]) {
    set<int> s;
    vector<bool> vis(V, false);

    auto dfs_cycle = [&](auto &dfs_cycle, int v) -> bool {
        vis[v] = true;
        s.insert(v);
        for(auto ch: adj[v]) {
            if(!vis[ch] && dfs_cycle(dfs_cycle, ch)) {
                return true;
            }
            else if(s.find(ch) != s.end()) {
                return true;
            }
        }
        s.erase(v);
        return false;
    };

    for(int i = 0; i < V; i++) {
        if(!vis[i] && dfs_cycle(dfs_cycle, i)) {
            return true;
        }
    }
    return false;
}
